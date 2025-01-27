/***********************************************************************
// OOP244 Workshop 4 lab: tester program
//
// File	main.cpp
// Version 1.0
// Date	2024/09/26
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
#include "Canister.h"
using namespace std;
using namespace seneca;
void showCans(const char* title, const Canister* boxArray, int num = 1);
int main() {
   int i;
   Canister C[]={
      Canister(20, 10, "Olive Oil"),
      Canister("Orange Juice"),
      Canister(40,30),
      Canister(),
      Canister(),
      Canister(nullptr),
      Canister(9,20, "Bad one"),
      Canister(20,9, "Bad one"),
      Canister(41,20, "Bad one"),
      Canister(20,31, "Bad one")
   };
   showCans("Six usable and four unusable Cans:", C, 10);
   for (i = 0; i < 9; i++) C[i].clear();
   showCans("Cleared Cans:", C, 10);
   C[0].setContent("Milk").pour(1200);
   C[1].setContent("Milk").pour(100);
   C[2].setContent("Olive Oil").pour(20000);
   C[3].setContent("Orange Juice").pour(500);
   C[5].setContent("Apple Juice");
   showCans("Good Containers", C, 5);
   showCans("Emptied Milk canister into another", &C[0].pour(C[1]), 2);
   C[4].pour(C[3]);
   showCans("Poured a canister of Orange Juice in an empty one", &C[3], 2);
   C[3].pour(C[2]);
   showCans("Poured from Olive Oil canister to an emtpy Orange juice canister", &C[2], 2);
   showCans("Poured 5000ccs into the Olive Oil canister", &C[2].pour(5000), 1);
   showCans("Filled can of milk with olive oil", &C[1].pour(C[2]), 2);
   showCans("Poured too much into Orange Juice canister", &C[4].pour(1500), 1);
   showCans("Filled the Apple Juice can with Olive Oil after cleaning", &C[5].clear().pour(C[2]), 1);

   showCans("All Cans at the end", C, 9);
   return 0;
}
void showCans(const char* title, const Canister* canArray, int num ) {
   cout << " " << title << endl;
   cout << " Capacity,  Dimensions            Volume     Content" << endl;
   cout << "------------------------------    ---------  ---------------------------" << endl;
   for (int i = 0; i < num; i++) {
      canArray[i].display() << endl;
   }
   cout << "------------------------------    ---------  ---------------------------" << endl << endl;
}

