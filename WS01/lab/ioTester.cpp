/***********************************************************************
// OOP244 Workshop #1: Tester Program
//
// File        ioTester.cpp
// Version     1.0
// Date        2025-05-13
// Author      Fardad Soleimanloo
// Description:
// Tests the "io" module functions for Workshop 1.
// Start developing the functions in the order they are tested.
// Uncomment the test functions one at a time from top to bottom,
// and compare their output to the expected output shown at the end
// of this file. When completed, test your program using main.cpp
// before submitting.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "io.h"
using namespace seneca;
using namespace std;

//Uncomment each function separately to test
//void testReadName() {
//   cout << "Testing: void read(char*)" << endl;
//   char name[81];
//   read(name);
//   cout << "Hello " << name << endl;
//   cout << "============================\n============================" << endl;
//}


//Uncomment each function separately to test
//void testReadFile() {
//   cout << "Testing: void print(const PhoneRec&, size_t&, const char* = nullptr)" << endl;
//   std::FILE* file = fopen("phones.tsv", "r");
//   PhoneRec pr{};
//   size_t row = 1;
//   if (file) {
//      while (read(pr, file)) {
//         cout << pr.m_name << ", " << pr.m_lastName << ", " << pr.m_phoneNumber << endl;
//      }
//      fclose(file);
//   }
//   else {
//      cout << "I could not fine phones.tsv" << endl;
//   }
//   cout << "============================\n============================" << endl;
//}



//Uncomment each function separately to test
//void testPrintNumber() {
//   cout << "Testing: void print(long long)" << endl;
//   long long N = 9999999999LL;
//   print(N);
//   cout << endl;
//   cout << "============================\n============================" << endl;
//}

//Uncomment each function separately to test
//void testPrintPhoneRec() {
//   cout << "Testing: void print(const PhoneRec&, size_t&, const char* = nullptr)" << endl;
//   const PhoneRec pr = { "John", "Doe", 4165551234 };
//   size_t row = 1;
//   print(pr, row);
//   print(pr, row, "Jo");
//   print(pr, row, "Do");
//   print(pr, row, "oh");
//   print(pr, row, "oe");
//   print(pr, row, "jake"); // nothing should be printed
//   cout << "============================\n============================" << endl;
//}


//Uncomment each function separately to test
//void testPrintPhonePtrs() {
//   cout << "Testing:void print(PhoneRec* [], size_t, const char* = nullptr)" << endl;
//   PhoneRec pr[3] = {
//      {"John", "Doe", 1231231234},
//      {"Jane", "Doe", 2342342345},
//      {"Jake", "Doe", 3453453456}
//   };
//   PhoneRec* ptrs[3] = { &pr[2], &pr[1], &pr[0] };
//   print(ptrs, 3, "ja");
//   cout << "---------------------------" << endl;
//   print(ptrs, 3);
//   cout << "============================\n============================" << endl;
//}


//Uncomment each function separately to test
//void testSetPointers() {
//   cout << "Testing:void setPointers(...)" << endl;
//   PhoneRec pr[3] = {
//      {"John", "Doe", 1231231234},
//      {"Jane", "Doe", 2342342345},
//      {"Jake", "Doe", 3453453456}
//   };
//   PhoneRec* ptrs[3];
//   setPointers(ptrs, pr, 3);
//   print(ptrs, 3);
//   cout << "============================\n============================" << endl;
//}


//Uncomment each function separately to test
//void testSort() {
//   cout << "Testing:void sort(...)" << endl;
//   PhoneRec pr[20];
//   PhoneRec* ptrs[20];
//   std::FILE* file = fopen("phones.tsv", "r");
//   for (size_t i = 0; read(pr[i], file); i++);
//   fclose(file);
//   setPointers(ptrs, pr, 20);
//   cout << "Phone Recorded sorty by name: " << endl;
//   sort(ptrs, 20, false);
//   print(ptrs, 20);
//   cout << "============================" << endl;
//   cout << "Phone Recorded sorty by last name: " << endl;
//   sort(ptrs, 20, true);
//   print(ptrs, 20);
//   cout << "============================\n============================" << endl;
//}

int main() {
//   testReadName();
//   testReadFile();
//   testPrintNumber();
//   testPrintPhoneRec();
//   testPrintPhonePtrs();
//   testSetPointers();
//   testSort();
   return 0;
}


/*
* 
* output fo each tester:
Testing: void read(char*)
Name
> John
Hello John
============================
============================

Testing: void print(const PhoneRec&, size_t&, const char* = nullptr)
Ralph, Wiggum, 5554445555
Homer, Simpson, 5551234567
Ned, Flanders, 5556789012
Montgomery, Burns, 5557891234
Waylon, Smithers, 5558901234
Moe, Szyslak, 5559012345
Marge, Simpson, 5552345678
Barney, Gumble, 5556123456
Bart, Simpson, 5553456789
Lenny, Leonard, 5551112222
Carl, Carlson, 5552223333
Milhouse, Van-Houten, 5553334444
Chief, Wiggum, 5555556666
Lisa, Simpson, 5554567891
Seymour, Skinner, 5556667777
Edna, Krabappel, 5557778888
Apu, Nahasapeemapetilon, 5558889999
Maggie, Simpson, 5555678901
Patty, Bouvier, 5559991234
Selma, Bouvier, 5551231111
============================
============================

Testing: void print(long long)
(999) 999-9999
============================
============================

Testing: void print(const PhoneRec&, size_t&, const char* = nullptr)
1: John Doe (416) 555-1234
2: John Doe (416) 555-1234
3: John Doe (416) 555-1234
4: John Doe (416) 555-1234
5: John Doe (416) 555-1234
============================
============================

Testing:void print(PhoneRec* [], size_t, const char* = nullptr)
---------------------------
1: Jake Doe (345) 345-3456
2: Jane Doe (234) 234-2345
3: John Doe (123) 123-1234
============================
============================

Testing:void setPointers(...)
1: John Doe (123) 123-1234
2: Jane Doe (234) 234-2345
3: Jake Doe (345) 345-3456
============================
============================

Testing:void sort(...)
Phone Recorded sorty by name:
1: Apu Nahasapeemapetilon (555) 888-9999
2: Barney Gumble (555) 612-3456
3: Bart Simpson (555) 345-6789
4: Carl Carlson (555) 222-3333
5: Chief Wiggum (555) 555-6666
6: Edna Krabappel (555) 777-8888
7: Homer Simpson (555) 123-4567
8: Lenny Leonard (555) 111-2222
9: Lisa Simpson (555) 456-7891
10: Maggie Simpson (555) 567-8901
11: Marge Simpson (555) 234-5678
12: Milhouse Van-Houten (555) 333-4444
13: Moe Szyslak (555) 901-2345
14: Montgomery Burns (555) 789-1234
15: Ned Flanders (555) 678-9012
16: Patty Bouvier (555) 999-1234
17: Ralph Wiggum (555) 444-5555
18: Selma Bouvier (555) 123-1111
19: Seymour Skinner (555) 666-7777
20: Waylon Smithers (555) 890-1234
============================
Phone Recorded sorty by last name:
1: Patty Bouvier (555) 999-1234
2: Selma Bouvier (555) 123-1111
3: Montgomery Burns (555) 789-1234
4: Carl Carlson (555) 222-3333
5: Ned Flanders (555) 678-9012
6: Barney Gumble (555) 612-3456
7: Edna Krabappel (555) 777-8888
8: Lenny Leonard (555) 111-2222
9: Apu Nahasapeemapetilon (555) 888-9999
10: Marge Simpson (555) 234-5678
11: Homer Simpson (555) 123-4567
12: Bart Simpson (555) 345-6789
13: Lisa Simpson (555) 456-7891
14: Maggie Simpson (555) 567-8901
15: Seymour Skinner (555) 666-7777
16: Waylon Smithers (555) 890-1234
17: Moe Szyslak (555) 901-2345
18: Milhouse Van-Houten (555) 333-4444
19: Ralph Wiggum (555) 444-5555
20: Chief Wiggum (555) 555-6666
============================
============================
*/