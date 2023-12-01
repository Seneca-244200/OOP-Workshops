/***********************************************************************
// OOP244 Workshop #1 DIY: tester program
//
// File  direcotry_prof.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Cristhian Rosero           Date            Reason
***********************************************************************/
#include <iostream>
#include "Phone.h"
#include "Phone.h"  // this is intentional
using namespace sdds;
int main() {
   std::cout << "Enter the following Data:" << std::endl
      << "-------------------------------------------------------\n"
         "lukE\nsky\nfett\nfeT\nJack\n!\n"
         "-------------------------------------------------------\n";
   phoneDir("Star Wars", "phones.txt");
   std::cout << std::endl << "-------------------------------------------------------" << std::endl;
   phoneDir("Broken Phone Book", "badDataFile.txt");
   return 0;
}