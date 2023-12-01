#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   
   //Read Functions
   //Scan for employee name
    bool read(char* empName) {
    
        bool ok = false;
    
        if (fscanf(fptr, "%[^\n]\n", empName) == 1) {
            ok = true;
        }
            
    return ok;
    }

    //Scan for employee number
    bool read(int& empNumber) {

        bool ok = false;

        if (fscanf(fptr, "%d,", &empNumber) == 1) {
            ok = true;
        }

        return ok;
    }

    //Scan for employee salary
    bool read(double& empSalary) {

        bool ok = false;

        if (fscanf(fptr, "%lf,", &empSalary) == 1) {
            ok = true;
        }

        return ok;
    }
}