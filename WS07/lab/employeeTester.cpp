#include <iostream>
#include <fstream>
#include "Employee.h"
using namespace std;
using namespace seneca;

void prnEmp();

int main() {
   Employee P("Edna Krabappel", 11222, 76543.0);
   P.title() << endl;
   P.write() << endl;
   cout << "Enter the following:" << endl;
   cout << "John Doe, 12312, 76543.0<ENTER>\n> ";
   cin >> P;
   cin.ignore(1000, '\n');
   cout << "You enterd:" << endl;
   P.title() << endl;
   cout << P << endl;
   prnEmp();
   return 0;
}
void prnEmp() {
   ifstream file("employees.csv");
   Employee P;
   cout << "List of employees in file!" << endl;
   P.title() << endl;
   while (file) {
      // Note that although the read method is specifically 
      // writted for ostream is works with ofstream as well.
      P.read(file).ignore(1000, '\n');  
      if (file) cout << P << endl;
   }
}