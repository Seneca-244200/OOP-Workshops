/***********************************************************************
// OOP244 Project/workshop, Utils Module
//
// File	Utils.h
// started by Fardad 
// Description
// utility function to be used in the project or workshops
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 0.2             11-6            added 3 argument strcpy 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

namespace seneca {
   class Utils {
   public:
      // Allocates memory for a copy of the source string and returns the copy
      char* alocpy(const char* src) const;

      // Copies the source string to the destination, allocating memory if necessary
      char* alocpy(char*& des, const char* src) const;

      // Copies the source string to the destination, assumes sufficient space is available
      char* strcpy(char* des, const char* src) const;

      // Copies up to 'len' characters from the source to the destination, null-terminates
      char* strcpy(char* des, const char* src, int len) const;

      // Returns the length of the string
      int strlen(const char* str) const;

      // Checks if a character is whitespace (space, tab, newline, etc.)
      bool isspace(char ch) const;

      // Checks if an entire C-string consists of whitespace characters
      bool isspace(const char* cstring) const;
   };

   extern Utils ut;   // Global Utils object for easy access to utility functions
   // Example usage: ut.strcpy(des, src);
}

#endif // !SENECA_UTILS_H
