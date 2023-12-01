#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "CarInventory.h"

using namespace std;

namespace sdds {
    CarInventory::CarInventory() {
        resetInfo();

    }
   
    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price, bool setData) {
        if (setData) {
            resetInfo();
            setInfo(type, brand, model, year, code, price);
        }
    }


    CarInventory::~CarInventory() {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
    }

    void CarInventory::resetInfo() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = -1;
        m_code = -1;
        m_price = -1.0;
    }

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;

        m_type = new char[strlen(type) + 1];
        strcpy(m_type, type);

        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);

        m_model = new char[strlen(model) + 1];
        strcpy(m_model, model);

        m_year = (year >= 1990) ? year : -1;
        m_code = (code >= 100 && code <= 999) ? code : -1;
        m_price = (price > 0) ? price : -1;

        return *this;
    }

    void CarInventory::printInfo() const {
        cout << "| " << left << setw(10) << m_type << " | " << setw(16) << m_brand << " | " << setw(16) << m_model << " | ";

        if (m_year != -1 && m_code != -1 && m_price != -1.0) {
            cout << setw(4) << m_year << " |  " << setw(3) << m_code << " |  " << setw(8) << right << fixed << setprecision(2) << m_price << " |" << endl;
        }
        else {
            cout << "   N/A   |   N/A |     N/A     |" << endl;
        }
    }



    bool CarInventory::isValid() const {
        return (m_type && m_brand && m_model && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0);
    }

    bool CarInventory::isSimilarTo(const CarInventory& car) const {
        if (!m_type || !m_brand || !m_model || !car.m_type || !car.m_brand || !car.m_model) {
            return false;
        }

        return (strcmp(m_type, car.m_type) == 0 && strcmp(m_brand, car.m_brand) == 0 && strcmp(m_model, car.m_model) == 0 && m_year == car.m_year);
    }

    int find_similar(CarInventory car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return i;
                }
            }
        }
        return -1;
    }
}
