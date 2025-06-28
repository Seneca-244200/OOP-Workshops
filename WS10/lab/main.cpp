/***********************************************************************
// OOP244 Workshop 10: Function Templates - Main Tester
//
// File: main.cpp
// Author: Fardad
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// -----------------------------------------------------------
***********************************************************************/
#include <iostream>
#include "Name.h"
#include "dynaCopy.h"
using namespace std;
using namespace seneca;

int main() {
   cout << "Stage 1: Testing two-argument dynaCopy" << endl;
   int nums1[4] = { 10, 20, 30, 40 };
   Name N1[4] = { "David", "Zari", "Lucas", "Mary" };

   // Two-argument dynaCopy tests
   int* n = dynaCopy(nums1, 4);
   Name* N = dynaCopy(N1, 4);

   cout << "Printing integer array with prnArray:" << endl;
   prnArray(n, 4);

   cout << "Printing Name array with prnArray:" << endl;
   prnArray(N, 4);

   cout << "\nStage 2: Testing three-argument dynaCopy" << endl;
   int nums2[5] = { 60, 70, 80, 90, 100 };
   Name N2[5] = { "Homer", "Bart", "Lisa", "Marge", "Maggie" };

   int* m = nullptr;
   Name* M = nullptr;

   // Three-argument dynaCopy tests
   m = dynaCopy(n, nums2, 5);
   M = dynaCopy(N, N2, 5);

   // Verifying destination matches return value
   if (m != n || M != N) {
      cout << "Error: The destination argument must match the return value of dynaCopy." << endl;
   }

   cout << "Printing updated integer array with prnArray:" << endl;
   prnArray(n, 5);

   cout << "Printing updated Name array with prnArray:" << endl;
   prnArray(N, 5);

   cout << "\nStage 3: Edge case testing" << endl;

   // Test with single-element arrays
   int singleNum[1] = { 42 };
   int* singleCopy = dynaCopy(singleNum, 1);
   cout << "Single integer array:" << endl;
   prnArray(singleCopy, 1);
   delete[] singleCopy;

   // Cleanup dynamically allocated memory
   delete[] n;
   delete[] N;
   return 0;
}
