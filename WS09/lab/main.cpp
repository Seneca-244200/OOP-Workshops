/***********************************************************************
// OOP244 workshop 9, main tester
//
// File	main.cpp
// Version 1.0
// Author Fardad
// Description
// 
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Transcript.h"
using namespace seneca;
using namespace std;
void displayTranscript(Transcript T) {
   cout << "****************************************************************************" << endl;
   cout << T << "****************************************************************************" << endl;

} 
int main() {
   Transcript T1("John Doe", 111456789);
   Transcript T2("Jane Doe", 122456789);

   T1.addMark("DBS211: Introduction to Database Systems", 77);
   T1.addMark("OOP244: Introduction to Object-Oriented Programming", 85);
   T1.addMark("SFT221: Software Testing", 55);
   T1.addMark("WEB222: Web Programming Principles", 70);
   T1.addMark("EAC234: Science Fiction", 90);
   T2.addMark("DBS211: Introduction to Database Systems", 90);
   T2.addMark("OOP244: Introduction to Object-Oriented Programming", 60);
   T2.addMark("SFT221: Software Testing", 80);
   T2.addMark("WEB222: Web Programming Principles", 75);
   T2.addMark("EAC234: Science Fiction", 85);
   cout << "Displaying T1 and T2 Transcripts:" << endl;
   displayTranscript(T1);
   displayTranscript(T2);

   cout << "Testing Assignment Operator (T1 = T2):" << endl;
   T1 = T1 = T2 = T2;
   displayTranscript(T1);

   return 0;
}