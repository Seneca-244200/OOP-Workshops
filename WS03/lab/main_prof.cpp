/***********************************************************************
// OOP244 Workshop #3 lab (part 1): tester program
//
// File  main_prof.cpp
// Version 1.0
// Author   Cornel Barna, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Train.h"
using namespace sdds;

int main() {
	int i;
	Train trains[7];
	char st[] = "Seneca Express A";
	for(i = 0; i < 7; i++) {
		trains[i].initialize();
	}
	trains[0].set(nullptr, 100, 945);;
	trains[1].set("", 100, 945);
	trains[2].set("VIA Rail Abitibi", -100, 945);
	trains[3].set("VIA Rail Abitibi", 100, 645);
	trains[4].set("VIA Rail Abitibi", 100, 2355);
	trains[5].set("Seneca Express", -1, -1);
	trains[6].set("VIA Rail Abitibi", 333, 2055);

	cout << "----------------------------------------" << endl;
	cout << "1. Testing the validation logic." << endl;
	cout << "(only trains[6] should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (i = 0; i < 7; ++i)
	{
		cout << "trains[" << i << "]: "
			<< (trains[i].isInvalid() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	//
	cout << "----------------------------------------" << endl;
	cout << "2. Testing the display function." << endl;
	cout << "----------------------------------------" << endl;
	for (i = 0; i < 7; ++i)
	{
		trains[i].display();
	}
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "3. Testing the member functions." << endl;
	cout << "----------------------------------------" << endl;
	for(i = 0; i <7; i++) {
		trains[i].set(st);
		trains[i].set(100+i*155, 630+i*100+i*6);
		st[15]++;
		cout << (i + 1) << ": ";
		if(trains[i].isInvalid()) {
			cout << "*************" << endl;
		} else {
			cout << trains[i].getName() << " leaves at " << trains[i].getDepartureTime() << " with " << trains[i].noOfPassengers() << " passengers." << endl;
		}
	}
	cout << "----------------------------------------" << endl << endl;
	for(i = 0; i < 7; i++) {
		trains[i].finalize();
	}
	return 0;
}
