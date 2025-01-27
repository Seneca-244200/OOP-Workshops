/***********************************************************************
// OOP244 Workshop 4 DIY: tester program
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
#include "Label.h"
#include "LabelMaker.h"
using namespace seneca;
using namespace std;
int main() {
   int noOfLabels;
   // Create a lable for the program title:
   Label 
      theProgram("/-\\|/-\\|", "Professor's Label Maker Program Tester"),
      EmptyOne1,
      EmptyOne2("ABCDEFGH");
   cout << "EmptyOne1" << endl;
   EmptyOne1.printLabel() << endl;
   cout << "EmptyOne2" << endl;
   EmptyOne2.printLabel() << endl;
   theProgram.printLabel() << endl << endl;
   cout << "Enter the follwing information:" << endl <<
      "# of Labels > 6\n"
      "1> Applied Problem Solving\n"
      "2> Computer Principles for Programmers\n"
      "3> Communicating Across Contexts (Enriched)\n"
      "4> Introduction to Programming Using C\n"
      "5> Introduction to UNIX/Linux and the Internet\n"
      "6> Computer Programming and Analysis, Co-op (Work-Integrated Learning option only)\n\n";

      // ask for number of labels to get created
   cout << "Number of labels to create: ";
   cin >> noOfLabels;
   cin.ignore(10000, '\n');
   // Create a LabelMaker for the number of 
   // the labels requested
   LabelMaker lblMkr(noOfLabels);
   // Ask for the label texts
   lblMkr.readLabels();
   // Print the labels
   lblMkr.printLabels();
   return 0;
}