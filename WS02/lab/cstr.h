#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H
namespace seneca{
   int strlen(const char* str);
   char* strcpy(char* des, const char* src);
   char* strcpy(char* des, const char* src, int len);
   char* strncpy(char* des, const char* src, int len);
   char* strcat(char* des, const char* src);
   int strcmp(const char* s1, const char* s2);
   int strcmp(const char* s1, const char* s2, int len);
   char tolower(char ch);
   char* tolower(char* des, const char* src);
   char* tolower(char* str);
   const char* strstr(const char* str, const char* find);
   bool isalpha(char ch);
   bool isspace(char ch);
}

#endif // !SENECA_CSTR_H


