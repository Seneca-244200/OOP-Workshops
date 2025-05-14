/***********************************************************************
// OOP244 Workshop #1: main module
//
// File        main.cpp
// Version     1.0
// Date        2025-05-13
// Author      Fardad Soleimanloo
// Description:
// A search application using the io module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "io.h"
using namespace seneca;
using namespace std;
const size_t NumberOfRecords = 20;
int menu() {
   int choice{};
   cout << "---------------------------" << endl
       << "1- Display records" << endl
      << "2- Sorted by last name" << endl
      << "3- Sorted by first name" << endl
      << "4- revert to original order" << endl
      << "5- Search" << endl
      << "---------------------------" << endl
      << "0- Exit" << endl
      << "Select an option\n> ";
   cin >> choice;
   return choice;
}

int main() {
   PhoneRec recs[NumberOfRecords] = {};
   PhoneRec* recPtrs[NumberOfRecords]= {};
   std::FILE* file = fopen("phones.tsv", "r");
   if (file) {
      size_t recordsRead = 0;
      bool done = false;
      for (; read(recs[recordsRead], file); recordsRead++);
      setPointers(recPtrs, recs, recordsRead);
      fclose(file);
      if (recordsRead > NumberOfRecords) {
         cout << "Too many records" << endl;
         done = true;
      }
      while (!done) {
         int choice = menu();
         switch (choice) {
         case 1:
            print(recPtrs, recordsRead);
            break;
         case 2:
            sort(recPtrs, recordsRead, true);
            cout << "Sorted By LAST NAME" << endl;
            print(recPtrs, recordsRead);
            break;
         case 3:
            sort(recPtrs, recordsRead, false);
            cout << "Sorted By FIRST NAME" << endl;
            print(recPtrs, recordsRead);
            break;
         case 4:
            setPointers(recPtrs, recs, recordsRead);
            cout << "REVERTED to original" << endl;
            print(recPtrs, recordsRead);
            break;
         case 5:{
            char name[26]{};
            read(name);
            print(recPtrs, recordsRead, name);
            break;
         }
         default:
            done = true;
         }
         cout << endl;
      }
   }
   else {
      cout << "File \"phones.tsv\" not found!" << endl;
   }
   cout << "Goodbye!" << endl;
   return 0;
}

