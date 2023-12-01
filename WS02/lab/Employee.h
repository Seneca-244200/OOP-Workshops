#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };

    //sorts the dynamic array of employees based on the GPA of the employees.
    void sort();

    // loads a employee structure with its values from the file
    bool load(struct Employee& emp);

    // allocates the dynamic array of employees and loads all the file
    // recoreds into the array
    bool load();

    // displays a employee record on the screen:
    void display(const Employee& emp);

    // first sorts the employees then displays all the employees on the screen
    void display();

    // first will deallocate all the names in the employee elements
    // then it will deallocate the employee array
    void deallocateMemory();



}
   
#endif 