/***********************************************************************
// OOP244 Workshop 4 DIY: tester program
//
// File	main.cpp
// Version 1.0
// Date	2024/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Mark.h"
using namespace std;
using namespace seneca;
int main() {
   Mark m, n(25), k(200), p(-10);
   cout << "int ............" << endl;
   cout << int(m) << endl;
   cout << int(n) << endl;
   cout << int(k) << endl;
   cout << int(p) << endl;
   cout << "+= ............." << endl;
   cout << int(m += 20) << endl;
   cout << int(n += 20) << endl;
   cout << int(k += 20) << endl;
   cout << int(n += 60) << endl;
   cout << "= .............." << endl;
   cout << int(m = 80) << endl;
   cout << int(n = 120) << endl;
   cout << int(k = 70) << endl;
   cout << "double ........." << endl;
   m = 50; n = 80; k = 120;
   cout << double(m) << endl;
   cout << double(n) << endl;
   cout << double(k) << endl;
   cout << "char ..........." << endl;
   cout << char(m) << endl;
   cout << char(n) << endl;
   cout << char(k) << endl;
   cout << "int += Mark ..." << endl;
   int val = 60;
   cout << (val += n) << endl;
   cout << (val += k) << endl;
   cout << "test all values" << endl;
   p = 41;
   val = 0;
   for (int i = 0; i < 12; i++) {
      p += 5;
      val += p;
      cout << int(p) << ": " << char(p) << ", " << double(p) << endl;
   }
   p = val / 12;
   cout << "Average: " << int(p) << " GPA: " << double(p) << endl;
   return 0;
}