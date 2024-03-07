/***********************************************************************
// OOP244 Workshop #5 p2: tester program
//
// File	main_prof.cpp
// Version 1.0
// Author Mohammad Shamas
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;
using namespace seneca;
void displayDetails(const Hero* heroes, int size);
int main() {

	Power powerlist1[4] = { 
		{"Flying", 2},
		{"Laser Eye", 8},
		{"Freezing Breath", 8},
		{"Super Strength", 2},
	};

	Power powerlist2[2] = {
		{"Super Speed", 8},
		{"Super Healing", 5}
	};

	Power powerlist3[3] = {
		{"Flying", 2},
		{"Super Strength", 2},
		{"Telepathy", 9}
	};

	Power powerlist4[3] = {
		{"Water Bending", 9},
		{"Super Strength", 2},
		{"Animal Telepathy", 9}
	};

	Power powerlist5[2] = {
		{"Strong Will", 10},
		{"Flying", 2}
	};

	Hero herolist[5] = {
		{"Superman", powerlist1, 4},
		{"Flash",powerlist2, 2},
		{"Martian-Man-Hunter",powerlist3,3},
		{"Aquaman",powerlist4,3},
		{"Green-Lantern",powerlist5,2},
	};
	// Test 1
	cout << "----------------------------------------" << endl;
	cout << "1. Testing the display function and constructors." << endl;
	cout << "----------------------------------------" << endl;
	displayDetails(herolist, 5);
	cout << "----------------------------------------" << endl << endl;
	// Test 2
	cout << "----------------------------------------" << endl;
	cout << "1. Testing the += operator" << endl;
	cout << "----------------------------------------" << endl;
	Power testing1 = {"Phasing through objects", 10};
	herolist[1] += testing1;
	herolist[1].display() << endl;
	herolist[2] += testing1;
	herolist[2].display() << endl;
	cout << "----------------------------------------" << endl << endl;
	// Test 3
	cout << "----------------------------------------" << endl;
	cout << "3. Testing the -= operator" << endl;
	cout << "----------------------------------------" << endl;
	herolist[1] -= 10;
	herolist[1].display() << endl;
	cout << "----------------------------------------" << endl << endl;
	// Test 4
	cout << "----------------------------------------" << endl;
	cout << "4. Testing the >> and << operators" << endl;
	cout << "----------------------------------------" << endl;
	Power testing2 = { "Regeneration", 5 };
	testing2 >> herolist[4];
	herolist[4].display() << endl;
	herolist[0] << testing2;
	herolist[0].display() << endl;
	cout << "----------------------------------------" << endl << endl;
	// Test 5
	cout << "----------------------------------------" << endl;
	cout << "5. Testing the < and > operators" << endl;
	cout << "----------------------------------------" << endl;
	cout << ((herolist[0] > herolist[2]) ? "Superman is stronger than Martian-Man-Hunter" : "Double check your < operator");
	cout << endl;
	cout << ((herolist[4] < herolist[3])? "Green-Lantern is weaker than Aquaman" : "Double check your < operator");
	cout << endl;
	cout << "----------------------------------------" << endl << endl;


	
	return 0;
}

void displayDetails(const Hero* heroes, int size) {
	cout << "Details of our heroes are as follow: " << endl;
	for (int i = 0; i < size; i++) {
		heroes[i].display() << endl;
	}
}