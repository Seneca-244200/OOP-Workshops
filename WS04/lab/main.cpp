/***********************************************************************
// OOP244 Workshop 4 lab: tester program
//
// File	main.cpp
// Version 1.0
// Date	2025/06/03
// Author	Fardad Soleimanloo
// Description
// Do not modify this code.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Account.h"
using namespace std;
using namespace seneca;
void displayAccounts(const Account* acc, int num,int startFrom = 0);
void displayAccount(const Account& acc);
void displayRawAccountNumber(const Account* acc, int num);
void displayRawBalances(const Account* acc, int num);
int countNewAccounts(const Account* acc, int num);
int countBadAccounts(const Account* acc, int num);
void prnIntials(const Account& A);
void toUpper(char& ch);
void capitalize(Account* Arr, int size);
void capitalize(Account& A);
void prnIntials(const Account& A);
void toUpper(char& ch);
void capitalize(Account* Arr, int size);
void capitalize(Account& A);
const size_t MixedSize = 13;
int main() {
   double value;
   Account mixed[MixedSize] = {
      {"Paul atreides", 11111, 111.11},  
      {"Duncan idaho", 22222, 222.22},  
      {"Piter de Vries", 333, 333.333},   // invalid
      {"Thufir Hawat", 44444, 4444.44},
      {"stilgar sremen", 55555, 555.55},
      {"chani Fremen", 66666, -66.66},  // invalid
      {"Gurney Halleck",77777, 777.77},
      {"Hubert claine Wolfeschlegelsteinhausenbergerdorff Sr.", 80000, 888.00},
      {"Leto Atreides" },
      {"vladimir Harkonnen"},
      {nullptr, 10101, 20.22}, // invalid
      {"", 20202, 30.33}       // invalid
   };
   cout << "Using bool conversion overload and operator ~ to print the accounts: " << endl;
   displayAccounts(mixed, MixedSize);
   capitalize(mixed, 10);
   cout << "Capitalized names: " << endl;
   displayAccounts(mixed, MixedSize);
   cout << "Depositing $50.02 into account #1 using += operator:" << endl;
   displayAccount(mixed[0] += 50.02);
   cout << "Withdrawing $100.01 from account #2 using -= operator:" << endl;
   displayAccount(mixed[1] -= 100.01);
   cout << "Attempting to withdraw too much from account #4 using -= operator:" << endl;
   displayAccount(mixed[3] -= 5555.55);
   cout << "Attempting to deposit and withdraw negative amounts on account #4:" << endl;
   displayAccount(mixed[3] -= -5.55);
   displayAccount(mixed[3] += -50.55);
   cout << "Having these two accounts: " << endl;
   displayAccounts(mixed, 2);
   cout << "Moving funds from first account to second:" << endl;
   mixed[0] >> mixed[1];
   displayAccounts(mixed, 2);
   cout << "Moving funds from second account to first:" << endl;
   mixed[0] << mixed[1];
   displayAccounts(mixed, 2);
   cout << "Attempting to move funds from an account to itself" << endl;
   displayAccount(mixed[0] << mixed[0]);
   cout << "Displaying all accounts: " << endl;
   displayAccounts(mixed, MixedSize);
   cout << "Sum of the balances of accounts 4 and 5: ";
   value = double(mixed[3]);
   value += double(mixed[4]);
   cout <<  value << endl;
   cout << "Attempting to change the account number of the valid account#7:" << endl;
   cout << "Before: " << endl;
   displayAccount(mixed[6]);
   cout << "After: " << endl;
   displayAccount(mixed[6] = 12121);
   cout << "Setting a new account (#9) to a valid account number 99999)" << endl;
   cout << "Before: " << endl;
   displayAccount(mixed[8]);
   cout << "After: " << endl;
   displayAccount(mixed[8] = 99999);

   cout << "Testing prefix operator++ [#7 = ++ #8]" << endl;
   cout << "Before: " << endl;
   displayAccounts(mixed, 2,6);
   mixed[6] = ++mixed[7];
   cout << "After: " << endl;
   displayAccounts(mixed, 2,6);

   cout << "Testing postfix operator++ [#7 = #8 ++]" << endl;
   cout << "Before: " << endl;
   mixed[6] = 1000.0;
   displayAccounts(mixed, 2,6);
   mixed[6] = mixed[7]++;
   cout << "After: " << endl;
   displayAccounts(mixed, 2,6);


   cout << "Testing prefix operator-- [#7 = -- #8]" << endl;
   cout << "Before: " << endl;
   mixed[6] = 1000.0;
   displayAccounts(mixed, 2,6);
   mixed[6] = --mixed[7];
   cout << "After: " << endl;
   displayAccounts(mixed, 2,6);

   cout << "Testing postfix operator-- [#7 = #8 --]" << endl;
   cout << "Before: " << endl;
   mixed[6] = 1000.0;
   displayAccounts(mixed, 2,6);
   mixed[6] = mixed[7]--;
   cout << "After: " << endl;
   displayAccounts(mixed, 2,6);



   displayRawAccountNumber(mixed, MixedSize);
   displayRawBalances(mixed, MixedSize);
   cout << "Total of " << countNewAccounts(mixed, MixedSize) << " new accounts" << endl;
   cout << "Total of " << countBadAccounts(mixed, MixedSize) << " invalid accounts" << endl;
   return 0;
}

void displayAccounts(const Account* acc, int num, int startFrom ) {
   cout << "+---+-----+--------------------------------+-------+--------------+" << endl;
   cout << "|ROW|Init | Name                           | ACC#  |    BALANCE   |" << endl;
   cout << "+---+-----+--------------------------------+-------+--------------+" << endl;
   num += startFrom;
   for (int i = startFrom; i < num; i++) {
      cout << "|";
      cout.width(3);
      cout.fill('0');
      cout << (i + 1) << "| ";
      prnIntials(acc[i]);
      cout << " |";
      cout.fill(' ');
      acc[i].display() << "|" << endl;
   }
   cout << "+---+-----+--------------------------------+-------+--------------+" << endl;
}
void displayAccount(const Account& acc) {
   displayAccounts(&acc, 1);
}
void displayRawAccountNumber(const Account* acc, int num) {
   cout << "Display raw account numbers of all the accounts " << endl;
   cout << " using int conversion operator" << endl;
   for (int i = 0; i < num; i++) {
      cout << int(acc[i]) << " ";
   }
   cout << endl;
}
void displayRawBalances(const Account* acc, int num) {
   cout << "Display raw balances of the accounts: " << endl;
   cout << " using double conversion operator" << endl;
   for (int i = 0; i < num; i++) {
      cout << double(acc[i]) << " ";
   }
   cout << endl;
}
int countNewAccounts(const Account* acc, int num) {
   int sum = 0;
   for (int i = 0; i < num; i++) {
      sum += ~acc[i];
   }
   return sum;
}
int countBadAccounts(const Account* acc, int num) {
   int sum = 0;
   for (int i = 0; i < num; i++) {
      sum += !acc[i] && !~acc[i];
   }
   return sum;
}

void prnIntials(const Account& A) {
   int p = 0;
   for (int i = 0; A[i] && i < NameMaxLen; i++) {
      if (i == 0) {
         cout << A[i];
         p++;
      }
      else if (A[i] == ' ') {
         cout << A[i + 1];
         p++;
      }
   }
   for (; p < 3; p++) {
      cout << " ";
   }
}

void toUpper(char& ch) {
   if (ch >= 'a' && ch <= 'z') {
      ch -= ('a' - 'A');
   }
}

void capitalize(Account* Arr, int size) {
   for (int i = 0; i < size; i++) {
      capitalize(Arr[i]);
   }
}

void capitalize(Account& A) {
   for (int i = 0; A[i] && i < NameMaxLen; i++) {
      if (i == 0) {
         toUpper(A[i]);
      }
      else if (A[i] == ' ') {
         toUpper(A[i + 1]);
      }
   }
}
