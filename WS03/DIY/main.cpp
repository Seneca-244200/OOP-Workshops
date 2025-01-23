/***********************************************************************
// OOP244 Workshop 3 DIY: tester program
//
// File	main.cpp
// Version 1.0
// Date	2024/09/16
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
#include <cstdio>
#include "TagList.h"
#include "NameTag.h"
using namespace seneca;
int noOfNames(FILE* fptr) {
   char ch;
   int recs = 0;
   rewind(fptr);
   while(fscanf(fptr, "%c", &ch) == 1) {
      recs += (ch == '\n');
   }
   rewind(fptr);
   return recs;
}
int main() {
   char name[51]{};
   FILE* fptr = fopen("simpsons.txt","r");
   NameTag nt;
   TagList tl;
   tl.set();
   tl.set(noOfNames(fptr));
   while(fscanf(fptr, "%[^\n]\n", name) == 1) {
      nt.set(name);
      tl.add(nt);
   }
   tl.print();
   tl.cleanup();
   fclose(fptr);
   return 0;
}