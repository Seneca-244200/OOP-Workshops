/***********************************************************************
// OOP244 Workshop 5 lab: tester program
//
// File	main.cpp
// Version 1.0
// Date	2024/09/27
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
#include "Account.h"
using namespace std;
using namespace seneca;
void displayAccounts(const Account* acc, int num) {
   cout << "+---+-------+--------------+" << endl;
   cout << "|ROW| ACC#  |    BALANCE   |" << endl;
   cout << "+---+-------+--------------+" << endl;
      for (int i = 0; i < num; i++) {
         cout << "|";
         cout.width(3);
         cout.fill('0');
         cout<< (i + 1) << "|";
         cout.fill(' ');
      acc[i].display() <<"|" << endl;
   }
      cout << "+---+-------+--------------+" << endl;
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
int main() {
   double value;
   Account mixed[10] = {
      {11111, 111.11},  
      {22222, 222.22},  
      {333, 333.333},   // invalid
      {44444, 4444.44},
      {55555, 555.55},
      {66666, -66.66},  // invalid
      {77777, 777.77}
   };
   cout << "Using bool conversion overload and operator ~ to print the accounts: " << endl;
   displayAccounts(mixed, 10);
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
   cout << "Sum of the balance of accounts 5 and 7"<< endl << "   in three different ways: ";
   cout << (value = mixed[4] + mixed[6]) << ", ";
   value = 0;
   value += mixed[4];
   value += mixed[6]; 
   cout << value << ", and ";
   value = double(mixed[4]);
   value += double(mixed[6]);
   cout << value << endl;
   cout << "Setting the account number of account#8 to 88888: "<< endl;
   cout << "before: " << endl;
   displayAccount(mixed[7]);
   cout << "After:  " << endl;
   displayAccount(mixed[7] = 88888);
   cout << "Moving the Account from Account# 8 to Account #9 using operator=:" << endl;
   cout << "Before: " << endl;
   displayAccounts(&mixed[7], 2);
   mixed[8] = mixed[7];
   cout << "After: " << endl;
   displayAccounts(&mixed[7], 2);
   cout << "Displaying all accounts: " << endl;
   displayAccounts(mixed, 10);
   cout << "Attempting to change the account number of the valid account#7:" << endl;
   displayAccount(mixed[6] = 12121);
   cout << "Attempting to set a account that are not new: (7 and 6)" << endl;
   cout << "This attempt should not affect either account" << endl;
   cout << "Before: " << endl;
   displayAccounts(&mixed[5], 2);
   mixed[5] = mixed[6];
   mixed[6] = mixed[5];
   cout << "After: " << endl;
   displayAccounts(&mixed[5], 2);
   cout << "Setting a new account (#8) to a valid account(#7)" << endl;
   cout << "Before: " << endl;
   displayAccounts(&mixed[6], 2);
   mixed[7] = mixed[6];
   cout << "After: " << endl;
   displayAccounts(&mixed[6], 2);


   displayRawAccountNumber(mixed, 10);
   displayRawBalances(mixed, 10);
   cout << "Total of " << countNewAccounts(mixed, 10) << " new accounts" << endl;
   cout << "Total of " << countBadAccounts(mixed, 10) << " invalid accounts" << endl;
   return 0;
}