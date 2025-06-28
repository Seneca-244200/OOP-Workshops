/***********************************************************************
// OOP244 Workshop 7 lab: tester program
//
// File	main.cpp
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//fardad           11-12           then date order in line 30 was incorrect
                                   it is fixed now
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <fstream>
#include "Professor.h"
using namespace std;
using namespace seneca;

void prnProf();

int main() {
   cout << "Workshop 7 tester Version 1.1.\nCorrected the order of data in console entery test\n"
                                           "==================================================" << endl;
   Professor P( "Edna Krabappel", "OOP345 - Object-Oriented Software Development Using C++", 3, 11222, 76543.0 );
   P.title() << endl;
   P.write() << endl;
   cout << "Enter the following:" << endl;
   cout << "John Doe, 12312, 65432,IPC144 - Introduction to Programming Using C,3<ENTER>\n> ";
   cin >> P;
   cin.ignore( 1000, '\n' );
   cout << "You enterd:" << endl;
   P.title() << endl;
   cout << P << endl;
   prnProf();
   return 0;
}
void prnProf() {
   ifstream file("professors.csv");
   Professor P;
   cout << "List of professors in file!" << endl;
   P.title() << endl;
   while (file) {
      P.read(file).ignore(1000, '\n');
      if (file) cout << P << endl;
   }
}