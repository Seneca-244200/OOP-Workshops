/***********************************************************************
// OOP244 Workshop #1 :  DIY tester program
//
// File	main.cpp
// Version 1.0
// Date 2024-08-22
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "utils.h"
#include "phone.h"
using namespace std;
using namespace seneca;

int main() {
   bool done = false;
   char contactName[51];
   cout << "Phone Directory Search" << endl;
   cout << loadPhones() << " records loaded!" << endl;
   do{
      cout << endl;
      displayMatchingNames(getName(contactName));
      cout << "Do another search? (Y)es: ";
   } while (yes());
   cout << "Goodbye!" << endl;
   return 0;
}