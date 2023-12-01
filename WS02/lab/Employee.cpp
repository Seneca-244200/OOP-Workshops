#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds {
     
      // Function to calculate the length of a C-style string
    int strLen(const char* s) {
        int len = 0;
        while (s[len] != '\0') {
            len++;
        }
        return len;
    }

    // Function to copy a portion of one C-style string to another
    void strnCpy(char* des, const char* src, int len) {
        for (int i = 0; i < len && src[i] != '\0'; i++) {
            des[i] = src[i];
        }
        des[len] = '\0';
    }

    int noOfEmployees;
    Employee* employees;

    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(struct Employee& emp) {

        bool ok = false;
        char name[128] = {};

        if (sdds::read(emp.m_empNo) && sdds::read(emp.m_salary) && sdds::read(name)) {
            emp.m_name = new char[sdds::strLen(name) + 1];
            sdds::strnCpy(emp.m_name, name, sdds::strLen(name));
            emp.m_name[sdds::strLen(name)] = '\0';
            ok = true;
        }
        return ok;
    }

    // Allocates the dynamic array of employees and loads all the file records into the array
    bool load() {

        bool ok = false;
        int i = 0;

        if (sdds::openFile(DATAFILE)) {
            noOfEmployees = sdds::noOfRecords();
            employees = new Employee[noOfEmployees];
            if (employees != nullptr) {
                for (i = 0; i < noOfEmployees; i++) {
                    if (load(employees[i])) { // Removed unnecessary casting
                        ok = true;
                    }
                    else {
                        cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                        ok = false;
                    }
                }
                sdds::closeFile();
            }
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    // Displays employee record on the screen
    void display(const Employee& emp) {

        cout << emp.m_empNo << ": " << emp.m_name << ", $" << emp.m_salary << endl;
    }

    // First sorts the employees, then displays all the employees on the screen
    void display() {

        cout
            << "Employee Salary report, sorted by employee number\n"
            << "no- Empno, Name, Salary\n"
            << "------------------------------------------------" << endl;

        sort();

        for (int i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            display(employees[i]); // Removed unnecessary casting
        }
    }

    // Implementation for the deallocateMemory function goes here
    void deallocateMemory() {

        for (int i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }

        delete[] employees;
    }
}
