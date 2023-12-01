#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
#include <iostream>
#include <cstring>
#include <iomanip>


namespace sdds {

    Train::Train() {
        name = nullptr;
        passengers = -1;
        departure = -1;
    }

    Train::~Train() {
        finalize();
    }

    void Train::initialize() {
        finalize();
        name = nullptr;
        passengers = -1;
        departure = -1;
    }

    bool Train::validTime(int value) const {
        int minutes = value % 100;
        return (value >= MIN_TIME && value <= MAX_TIME && minutes >= 0 && minutes <= 59);
    }


    bool Train::validNoOfPassengers(int value) const {
        return (value >= 0 && value <= MAX_NO_OF_PASSENGERS);
    }

    void Train::set(const char* trainName) {
        finalize();

        if (trainName != nullptr && trainName[0] != '\0') {
            name = new char[strlen(trainName) + 1];
            strcpy(name, trainName);
        }
        else {
            // If the name is nullptr or an empty string, set the train to an invalid state
            finalize(); // Release any memory allocated for the name
            passengers = -1;
            departure = -1;
        }
    }

    void Train::set(int noOfPassengers, int departureTime) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departureTime)) {
            passengers = noOfPassengers;
            departure = departureTime;
        }
        else {
            passengers = -1;
            departure = -1;
        }
    }


    void Train::set(const char* trainName, int noOfPassengers, int departureTime) {
        finalize();

        if (trainName != nullptr && trainName[0] != '\0') {
            name = new char[strlen(trainName) + 1];
            strcpy(name, trainName);
            if (validNoOfPassengers(noOfPassengers) && validTime(departureTime)) {
                passengers = noOfPassengers;
                departure = departureTime;
            }
            else {
                passengers = -1;
                departure = -1;
            }
        }
        else {
            // If the name is nullptr or an empty string, set the train to an invalid state
            name = nullptr; // Release any memory allocated for the name
            passengers = -1;
            departure = -1;
        }
    }


    void Train::finalize() {
        delete[] name;
        name = nullptr;
    }

    bool Train::isInvalid() const {
        return (passengers == -1 || departure == -1);
    }

    int Train::noOfPassengers() const {
        return passengers;
    }

    const char* Train::getName() const {
        return name;
    }

    int Train::getDepartureTime() const {
        return departure;
    }

void Train::display() const {
    if (!isInvalid()) {
        std::cout << "NAME OF THE TRAIN:    " << std::setw(1) << std::setfill(' ') << (name ? name : "N/A") << std::endl;
        std::cout << "NUMBER OF PASSENGERS: " << passengers << std::endl;
        std::cout << "DEPARTURE TIME:       " << std::setw(4) << std::setfill('0') << departure << std::endl;
    }
    else {
        std::cout << "Train in an invalid State!" << std::endl;
    }
}


}