/***********************************************************************
// OOP244 Workshop #03 p1: tester program
//
// File	main.cpp
// Version 1.0
// Date: September 28, 2023
// Author: Yosef Ashibani, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Customer.h"
#include "Car.h"

using namespace std;
using namespace seneca;

void serviceReport(Customer& customer) {
   cout << "Servide Report - .........................................." << endl;
   if (!customer.isEmpty() && !customer.car().isEmpty()) {
      cout << "Customer Details:" << endl;
      customer.display();
   }
   else {
      cout << "Missing information.......................incomplete Entry:" << endl;
      if (customer.isEmpty()) {
         cout << "                   Customer infomration is missing." << endl;
      }
      if (!customer.isEmpty() && customer.car().isEmpty()) {
         cout << "                   Car information is missing." << endl;
      }
   }
}

int main() {
   const int numOfCustomers = 5;

   Car cars[numOfCustomers+1];
   Customer customers[numOfCustomers];
   for (int i = 0; i < numOfCustomers; i++) {
      cars[i].setEmpty();
      customers[i].setEmpty();
   }
   cars[numOfCustomers].setEmpty();

   cars[0].set("ABC123", nullptr, "Engine oil change", 50.0);// invalid
   cars[1].set("ABC1234", "Toyota Camry", nullptr, 50.0);    // invalid
   cars[2].set("DEFG1234", "", "Air filter change", 9.0);    // invalid
   cars[3].set("ABC", "Toyota Camry", "", 50.0);             // invalid
   cars[4].set("ABC", "Toyota Camry", "Engine oil change", 50.0);  // valid

   for (int i = 0; i < numOfCustomers + 1; i++) {
      cout << '[' << i << "] +++++++++++++" << endl;
      cars[i].display();
      cout << "-----------------" << endl;
   }

   customers[0].set(1001, "John Carter", nullptr);
   customers[1].set(1002, nullptr, &cars[1]);
   customers[2].set(1003, "", &cars[2]);
   customers[3].set(1004, "Bob Johnson", &cars[3]);
   customers[4].set(1005, "Jane Smith", &cars[4]);

   for (int i = 0; i < numOfCustomers; i++) {
      serviceReport(customers[i]);
      cars[i].deallocateMemory();
      customers[i].deallocateMemory();
   }
   cars[numOfCustomers].deallocateMemory();
   return 0;

}



