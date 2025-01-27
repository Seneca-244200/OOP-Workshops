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


   int strcmp(const char* s1, const char* s2, int len) {
      int i = 0;
      while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
         i++;
      }
      return s1[i] - s2[i];
   }

   const char* strstr(const char* str, const char* find) {
      const char* faddress = nullptr;
      int i, flen = strlen(find), slen = strlen(str);
      for (i = 0; i < slen - flen && strcmp(&str[i], find, flen); i++);
      if (i < slen - flen) faddress = &str[i];
      return faddress;
   }
   void strcat(char* des, const char* src) {
      int len = strlen(des);
      int i = 0;
      while (src[i]) {
         des[i + len] = src[i];
         i++;
      }
      des[i + len] = 0;
   }

}