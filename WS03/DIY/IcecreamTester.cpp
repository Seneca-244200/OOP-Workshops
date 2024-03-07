/***********************************************************************
// OOP244 Workshop #03 p2: tester program 
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
#include "IceCream.h"
int main() {
   seneca::Icecream I;
   // test one
   I.getOrder();
   I.printOrder();
   // test two
   I.getOrder();
   I.printOrder();
   return 0;
}