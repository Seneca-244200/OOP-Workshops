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
#include <iostream>
#include "Utils.h"

using namespace std;

namespace seneca {
   Utils ut; // Global instance of Utils for utility function access

   // Allocates memory and copies the source string to the newly allocated memory
   char* Utils::alocpy(const char* src) const {
      char* des{};
      return alocpy(des, src);
   }

   // Replaces the destination with a new copy of the source, deallocating old memory if necessary
   char* Utils::alocpy(char*& des, const char* src) const {
      delete[] des; // Free any existing memory
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1]; // Allocate memory for copy
         strcpy(des, src);                // Copy content
      }
      return des;
   }

   // Copies the source string to the destination, assumes enough space is available
   char* Utils::strcpy(char* des, const char* src) const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0); // Null-terminate
      return des;
   }

   // Copies up to 'len' characters from the source to the destination, null-terminates the destination
   char* Utils::strcpy(char* des, const char* src, int len) const {
      int i;
      for (i = 0; i < len && src[i]; i++) des[i] = src[i];
      des[i] = 0; // Ensure null-termination, unlike std::strncpy
      return des;
   }

   // Returns the length of the string (number of characters before the null terminator)
   int Utils::strlen(const char* str) const {
      int len;
      for (len = 0; str[len]; len++); // Count until null terminator
      return len;
   }

   // Checks if the given character is a whitespace character (space, tab, newline, etc.)
   bool Utils::isspace(char ch) const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   // Checks if the entire C-string is whitespace, returns true if all characters are whitespace
   bool Utils::isspace(const char* cstring) const {
      while (cstring && isspace(*cstring)) { // Check each character
         cstring++;
      }
      return cstring && *cstring == 0; // Returns true if all characters were whitespace
   }

}
