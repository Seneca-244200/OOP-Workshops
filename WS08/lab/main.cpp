/***********************************************************************
// OOP244 Workshop 8 lab: tester program
//
// File	main.cpp
// Version 1.0
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
#include <fstream>
#include "Shape.h"
#include "Rectangle.h"
#include "Line.h"
using namespace seneca;
using namespace std;
int main() {
   cout << "Nothing should be printed between these two lines" << endl;
   cout << "------------------------------------" << endl;
   cout << Line();
   cout << "------------------------------------" << endl;
   cout << "Rectangle size correction:" << endl;
   cout << Rectangle("Bas Size", 1, 1) << endl;
   Line* L = new Line("Separator", 50);
   Rectangle* R = new Rectangle("Container", 30, 5);
   Shape* S[2] = { L, R };
   cout << *L << endl;
   cout << *R << endl;
   cout << "Enter the following:\n>Line two,40<ETNER>\n>";
   cin >> *L;
   cout << "The following outputs should be the same" << endl;
   cout << "The correct output:" << endl;
   cout << "Line two\n========================================" << endl;
   cout << "Your output:" << endl;
   cout << *L << endl;
   cout << "Enter the following:\n>A 50 by 4 frame to be printed on screen,50,4<ETNER>\n>";
   cin >> *R;
   cout << "The following outputs should be the same" << endl;
   cout << "The correct output:" << endl;
   cout << "+------------------------------------------------+\n"
           "| A 50 by 4 frame to be printed on screen        |\n"
           "|                                                |\n"
           "+------------------------------------------------+" << endl;
   cout << "Your output:" << endl;
   cout << *R << endl;
   cout << "printing Line and Rectangle using Shape pointers: " << endl;
   cout << *S[0] << endl << *S[1] << endl;
   delete S[0];
   delete S[1];
   cout << "Reading the data from a file to check your\ninsertion and extraction helpers" << endl;
   ifstream file("ws8data.csv");
   Shape* sptr;
   char type;
   while (file) {
      sptr = nullptr;
      type = 'x';
      file.get(type);
      file.ignore();
      if (type == 'L') {
         sptr = new Line;
      }
      else if(type == 'R') {
         sptr = new Rectangle;
      }
      if (sptr) {
         file >> *sptr;
         cout << *sptr << endl;
         delete sptr;
      }
   }
   return 0;
}