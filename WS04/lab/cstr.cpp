#include "cstr.h"
namespace seneca {
   void freeMem(char*& mem)
   {
      delete[] mem;
      mem = nullptr;
   }
   bool alocpy(char*& des, const char* src) {
      freeMem(des);
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return bool(des);
   }
   unsigned int strlen(const char* src) {
      unsigned int len = 0;
      while (src[len]) len++;
      return len;
   }
   void strcpy(char* des, const char* src)
   {
      unsigned int i = 0;
      while (src[i]) {
         des[i] = src[i];
         i++;
      }
      des[i] = char(0);
   }
   void strcpy(char* des, const char* src, unsigned int maxLen) {
      unsigned int i;
      for (i = 0u; i < maxLen && src[i]; i++) {
         des[i] = src[i];
      }
      des[i] = 0;
   }
   int strcmp(const char* s1, const char* s2) {
      int i = 0;
      while (s1[i] && s2[i] && s1[i] == s2[i]) {
         i++;
      }
      return s1[i] - s2[i];
   }

}