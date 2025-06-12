/***********************************************************************
// OOP244 Workshop 5: tester program
//
// File	main.cpp
// Version 1.0
// Date	2025/06/12
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

void displayTest();
void displayHelperTest();
void insertionHelperTest();
void istreamExtractionTest();
void ifstreamExtractionTest();
void operatorPlusHelperTest();
void operatorMinusHelperTest();
void friendPperatorDivisionHelperTest();

int main() {
   displayTest();
   displayHelperTest();
   insertionHelperTest();
   istreamExtractionTest();
   ifstreamExtractionTest();
   operatorPlusHelperTest();
   operatorMinusHelperTest();
   friendPperatorDivisionHelperTest();
   return 0;
}

void displayTest() {
   int val = -1;
   while (val < 105) {
      Mark(val).display() << " - ";
      Mark(val, GPA).display() << " - ";
      Mark(val, GRADE).display() << endl <<
      "==============" << endl;
      val += 4;
   }
}

void displayHelperTest() {
   Mark M(47);
   while (M) {
      display(M, MARK) << endl;
      display(M, GRADE) << endl;
      display(M, GPA) << endl <<
         "==============" << endl;
      M += 15;
   }

}

void insertionHelperTest() {
   Mark M(47), G, P;
   P = G = M;
   P = GPA;
   G = GRADE;
   while (M) {
      cout << M << ": " << G << ", " << P << endl << "===============" << endl;
      M += 15;
      G += 15;
      P += 15;
   }
}

void istreamExtractionTest() {
   Mark M;
   cout << "Please enter the mark:\n> ";
   cin >> M;
   M = MARK;
   cout << "You entered: " << M << endl;
}

void ifstreamExtractionTest() {
   ifstream file("marks.csv");
   Mark M;
   while (file) {
      file >> M;
      if (file)
         cout << M << endl;
   }
}

void operatorPlusHelperTest() {
   Mark M(77.7);
   double r, v = 20.0;
   int ir, iv = 20;
   r = v + M;
   ir = iv + M;
   cout.precision(1);
   cout.setf(ios::fixed);
   cout << "double: " << r << endl;
   cout << "   int: " << ir << endl;
}

void operatorMinusHelperTest() {
   Mark M(30.7);
   double r, v = 99.9;
   int ir, iv = 99;
   r = v - M;
   ir = iv - M;
   cout.precision(1);
   cout.setf(ios::fixed);
   cout << "double: " << r << endl;
   cout << "   int: " << ir << endl;

}

void friendPperatorDivisionHelperTest() {
   Mark M(30.3);
   double r, v = 99.9;
   int ir, iv = 99;
   r = v / M;
   ir = iv / M;
   cout.precision(1);
   cout.setf(ios::fixed);
   cout << "double: " << r << endl;
   cout << "   int: " << ir << endl;

}
