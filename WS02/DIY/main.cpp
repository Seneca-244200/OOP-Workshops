/***********************************************************************
// OOP244 Workshop #2 : DIY tester program
//
// File	main.cpp
// Version 1.0
// Date	2024/08/25
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Population.h"
using namespace seneca;
int main() {
   if (load("PCpopulations.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}