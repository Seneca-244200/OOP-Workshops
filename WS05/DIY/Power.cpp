#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Power.h"

using namespace std;

namespace seneca {

	Power::Power() {
		setEmpty();
	}
	Power::Power(const char* name, int rarity) {
		createPower(name, rarity);
	}
	void Power::setEmpty() {
		m_name[0] = '\0';
		m_rarity = 0;
	}
	void Power::createPower(const char* name, int rarity) {
		if (name && name[0] != '\0' && rarity > 0) {
			strncpy(m_name, name, MAX_NAME_LENGTH);
			m_rarity = rarity;
		}
		else {
			setEmpty();
		}
	}
	const char* Power::checkName() const {
		return m_name;
	}
	int Power::checkRarity() const {
		return m_rarity;
	}
	bool Power::isEmpty() const {
		return (m_name[0] == '\0' || m_rarity == 0 );
	}
	void displayDetails(Power* powers, int size) {
		cout << "List of available powers: " << endl;
		for (int i = 0; i < size; i++) {
			if (!powers[i].isEmpty()) {
				cout << "  Name: " << powers[i].checkName() << ", "
					<< "Rarity: " << powers[i].checkRarity() << endl;
			}
		}
	}
}