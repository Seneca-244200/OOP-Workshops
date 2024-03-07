/***********************************************************************
// OOP244 Workshop # 6, tester program
//
// File: main.cpp
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file tests workshop six
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include <iostream>
#include <fstream>
#include "EmailFile.h"
using namespace seneca;
using namespace std;

int main() {

   // 1. Default constructor test
   EmailFile eFile;
   cout << eFile << endl; // Expected to show nothing

   // 2. Test bad file
   EmailFile eFileBad("BadFile.csv");

   cout << endl;
   // 3. Parametric constructor test
   EmailFile eFile2("emailFile_test1.csv");
   cout << eFile2 << endl;

   // 4. Copy the content to a new file and load the backup:
   if (eFile2.saveToFile("backupEmails.csv"))
   {
      cout << "Emails saved to backupEmails.csv" << endl;
   }
   EmailFile eFile3("backupEmails.csv");
   cout << eFile3 << endl;

   // 5. Copy constructor test
   EmailFile eFile4(eFile3);
   cout << eFile4 << endl;

   // 6. Operator= test
   eFile = eFile4;
   cout << eFile << endl;

   // 7. Testing fileCat function (concatenation)
   EmailFile eFile5("emailFile_test2.csv");
   eFile3.fileCat(eFile5);
   cout << eFile3 << endl;
   eFile3.fileCat(eFile5, "copyEmailFile.csv");
   EmailFile eFile6("copyEmailFile.csv");
   cout << eFile6 << endl;


   return 0;
}
