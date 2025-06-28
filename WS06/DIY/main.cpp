/***********************************************************************
// OOP244 Workshop 6 lab: tester program
//
// File	main.cpp
// Version 1.0
// Date	2024/10/28
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
#include <string>
#include "Stats.h"
using namespace seneca;
using namespace std;

void twentyNumbers(Stats T);
void badIndex(const Stats& T);
void Copy(const string& dest, const string& source);
void Dump(const string& filename);
int main() {
   Copy("numLtl.csv", "numbersLtlOriginal.csv");
   Copy("numbers.csv", "numbersOriginal.csv");
   Stats L(10, 7, 0);
   Stats S("numLtl.csv"), Empty, BadFilename("badFilename");
   cout << "Type numbers.csv and hit <ENTER>" << endl;
   cout << "Enter the data file name: ";
   cin >> L;
   cout << L << endl;
   cout << S << endl;
   twentyNumbers(L);
   twentyNumbers(S);
   cout << "Total of " << L.size() << " numbers in " << L.name() << endl; 
   L[1000] = 11111.11;
   L.occurrence(-12345.0, 31342.55);
   L.sort(true);

   cout << "Sorted Ascending: " << endl;
   L.occurrence(-12345.0, 31342.55);
   L.sort(false);
   cout << "Sorted Descending: " << endl;
   L.occurrence(-12345.0, 31342.55);
   L = S;
   cout << L << endl;
   cout << "============================================================" << endl;
   Dump("numbers.csv");
   Dump("numLtl.csv");
   Dump("C_numbers.csv");
   Dump("C_numLtl.csv");
   cout << "Empty object tests: " << endl;
   cout << "*" << Empty << BadFilename << "*" << endl;
   cout << Empty[10] << endl;
   badIndex(Empty);
   Empty.sort(true);
   Empty.occurrence(1, 2);
   cout << Empty.size() << endl;
   return 0;
}
void twentyNumbers(Stats T) {
   if (T) {
      cout << ">>> 20 numbers of : " << T.name() << endl;
      cout.setf(ios::fixed);
      cout.precision(1);
      for (unsigned i = 0; i < 200;i+=10) {
         cout << "T[" << i << "]: " << T[i] << endl;
      }
      cout.unsetf(ios::fixed);
   }
   else {
      cout << "Nothing to print!" << endl;
   }
   cout << endl << "-------------------------------------------------------------" << endl;
}
void Dump(const string& filename) {
   cout << "DUMP---------------------------------------------------------" << endl;
   cout << ">>>" << filename << "<<<" << endl ;
   ifstream fin(filename.c_str());
   int i = 0;
   char ch;
   while (fin.get(ch)) {
      if (i++ % 80 == 0) cout << endl;
      cout << ch;
   }
   cout << endl << "-------------------------------------------------------------" << endl;
}
void Copy(const string& dest, const string& source) {
   ifstream fin(source.c_str());
   ofstream fout(dest.c_str());
   char ch;
   while (fin.get(ch)) fout << ch;
}
void badIndex(const Stats& T) {
   cout << T[10] << endl;
}
