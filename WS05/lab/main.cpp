/***********************************************************************
// OOP244 Workshop #5 Lab (part 1): tester program
//
// File  main.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include "bankaccount.h"

using namespace std;
using namespace seneca;

void displayAllAccts(void);
void notifyFailure(void);

// create global bank accounts for testing
bankAccount joe, cindy, raya, rohan, ira;

int main()
{
	// Setup Accounts: Note account for Ira is intentionaly NOT setup 
	cout << "** Testing Account Setup **" << endl;

	if (!joe.setup("Joe Williams", true))
		notifyFailure();
	if (!cindy.setup("Cindy Kofler", false))
		notifyFailure();
	if (!raya.setup("Raya Chandok", false))
		notifyFailure();
	if (!rohan.setup("Rohan Kumar", true))
		notifyFailure();

	// Credit & Debit 
	if (!(joe += 100))
		notifyFailure();
	if (!(cindy += 0))
		notifyFailure();
	if (!(raya -= 5))
		notifyFailure();
	if (!(rohan += 5))
		notifyFailure();
	if ((ira += 5000))
		notifyFailure();

	// Cast Operators
	cout << "** Testing Cast operators **" << endl;
	if ((double)raya != -5)
		notifyFailure();
	if (!(bool)rohan)
		notifyFailure();
	if ((bool)ira)
		notifyFailure();

	// Transfer between accounts
	cout << "** Testing Fund Transfers **" << endl;
	if (!(cindy<<joe))
		notifyFailure();
	if (!(raya<<rohan))
		notifyFailure();
	if (joe << ira)
		notifyFailure();

	displayAllAccts();

	// Make Multiple Transactions
	for (int i = 1; i <= 10; i++)
	{
		raya	-= i;
		cindy	-= i * 2;
		joe		+= i;
		rohan	+= i * 2;
	}
	displayAllAccts();

	// Deduct Fees
	cout << "** Testing Fees **" << endl;
	--joe;
	--cindy;
	--raya;
	--rohan;
	--ira;
	displayAllAccts();

	// Apply Interest
	cout << "** Testing Interest **" << endl;
	++joe;
	++cindy;
	++raya;
	++rohan;
	++ira;
	displayAllAccts();

	cout << "** Testing Comparison operators **" << endl;
	if (!(joe <= (double)41.0))
		notifyFailure();
	if (!(cindy > (double)-53.0))
		notifyFailure();
	if (!((double)-96 > raya))
		notifyFailure();
	if (!((double)95 <= rohan))
		notifyFailure();

	cout << "** Testing Equality operator **" << endl;
	if (joe == rohan)
		notifyFailure();

	bankAccount twin1("Lian Zhou", false);
	bankAccount twin2("Lian Zhou", false);
	twin1 += 5; twin2 += 5;
	if (!(twin1 == twin2))
		notifyFailure();

	cout << "** All Tests Complete - Done **" << endl;
}

void displayAllAccts(void)
{
	joe.display();
	cindy.display();
	raya.display();
	rohan.display();
	ira.display();
}

void notifyFailure()
{
	cout << "main() FAILURE: Fix before proceeding further!" << endl;
}