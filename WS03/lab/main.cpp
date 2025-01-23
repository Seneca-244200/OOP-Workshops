/***********************************************************************
// OOP244 Workshop 3 lab: tester program
//
// File	main.cpp
// Version 1.0
// Date	2024/09/11
// Author	Fardad Soleimanloo
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
#include <cstdio>
#include "CC.h"
using namespace std;
using namespace seneca;
void listCCs();
int main() {
   CC cc;
   cc.set();
   cc.set("Hubert Blaine", 4098765423457896, 100);
   cout << "Valid credit card record: " << endl;
   cc.display();
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   cout << "Valid credit card with very long name: " << endl;
   cc.set("Hubert Blaine Wolfeschlegelsteinhausenbergerdorff Sr.", 4098765423457896, 123, 1, 32);
   cc.display();
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   cout << "Invalid credit card with short name: " << endl;
   cc.set("H", 4098765423457896, 999, 12, 32);
   cc.display();
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   cc.set("Hubert Blaine", 4098765423457896, 123, 0, 25);
   cout << "Invalid credit card record with bad month: " << endl;
   cc.display();
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   cc.set("Hubert Blaine", 4098765423457896, 123, 13, 25);
   cout << "Invalid credit card record with bad month: " << endl;
   cc.display();
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   cc.set("Hubert Blaine", 4098765423457896, 123, 13, 23);
   cout << "Invalid credit card record with bad year: " << endl;
   cc.display();
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   cc.set("Hubert Blaine", 4098765423457896, 123, 13, 33);
   cout << "Invalid credit card record with bad year: " << endl;
   cc.display();
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   cc.set("Hubert Blaine", 4098765423457896, 99, 13, 33);
   cout << "Invalid credit card record with bad cvv: " << endl;
   cc.display();
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   cc.set("Hubert Blaine", 4098765423457896, 1000, 13, 33);
   cout << "Invalid credit card record with bad cvv: " << endl;
   cc.display();
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   cc.cleanUp();
   listCCs();
   return 0;
}
void listCCs() {
   char name[71]{};
   unsigned long long no{};
   short ccv{};
   short expMon{};
   short expYear{};
   int numRead{};
   unsigned int row{};
   FILE* ccfile = fopen("cc.csv", "r");
   CC cc;
   cout << "|     |                                |                     |     | Expiry|" << endl;
   cout << "| Row | Card holder name               | Credit card number  | CVV | MM/YY |" << endl;
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   cc.set();
   do {
      numRead = fscanf(ccfile, "%[^,],%llu,%hd,%hd,%hd\n", name, &no, &ccv, &expMon, &expYear);
      if (numRead == 5) {
         cc.set(name, no, ccv, expMon, expYear);
         cout << "| ";
         cout.width(3);
         cout.setf(ios::left);
         cout << ++row;
         cout.unsetf(ios::left);
         cout << " ";
         cc.display();
         cc.cleanUp();
      }
   } while(numRead==5);
   cout << "+-----+--------------------------------+---------------------+-----+-------+" << endl;
   if (ccfile) fclose(ccfile);
}