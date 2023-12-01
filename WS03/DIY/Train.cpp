
#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
#include <iostream>
#include <cstring>

namespace sdds {
   
    void Train::initialize() {
        name = "";
        passengers = 0;
        maxPassengers = 0;
        departureTime = 0;
        validState = false;
        totalPassengersBoarded = 0;
    }

    void Train::set(const char* trainName, int maxPass, int departTime) {
        if (trainName != nullptr && trainName[0] != '\0' && maxPass >= 0 && departTime >= MIN_TIME && departTime <= MAX_TIME) {
            name = trainName;
            maxPassengers = maxPass;
            departureTime = departTime;
            validState = true;
        }
        else {
            initialize(); // Set to an invalid state
        }
    }

    void Train::set(int maxPass, int departTime) {
        if (maxPass >= 0 && departTime >= MIN_TIME && departTime <= MAX_TIME) {
            maxPassengers = maxPass;
            departureTime = departTime;
        }
        else {
            initialize(); // Set to an invalid state
        }
    }

    bool Train::isInvalid() const {
        return !validState;
    }

    int Train::getDepartureTime() const {
        return departureTime;
    }

    void Train::display() const {
        if (isInvalid()) {
            std::cout << "Train is in an invalid state!" << std::endl;
        }
        else {
            std::cout << "NAME OF THE TRAIN:    " << name << std::endl;
            std::cout << "NUMBER OF PASSENGERS: " << passengers << std::endl;
            std::cout << "DEPARTURE TIME:       " << departureTime << std::endl;
        }
    }

    bool Train::load(int& notBoarded) {
        if (isInvalid()) {
            notBoarded = 0;
            return false;
        }
        int passengersToAdd;
        std::cout << "Enter number of passengers boarding:" << std::endl << "> ";
        std::cin >> passengersToAdd;
        if (passengers + passengersToAdd > maxPassengers) {
            notBoarded = passengersToAdd + passengers - maxPassengers;
            passengers = maxPassengers;
        }
        else {
            passengers += passengersToAdd;
            notBoarded = 0;
        }
        return true;
    }


    bool Train::updateDepartureTime() {
        int newDepartureTime;
        std::cout << "Enter new departure time:" << std::endl << "> ";
        std::cin >> newDepartureTime;

        // Check if the new departure time is within the valid range
        if (newDepartureTime >= MIN_TIME && newDepartureTime <= MAX_TIME) {
            departureTime = newDepartureTime;
            validState = true; // Update the valid state
            return true;
        }
        else {
            departureTime = -1; // Invalid departure time
            validState = false; // Update the valid state
            return false;
        }
    }


    void Train::finalize() {
        initialize();
    }

    // Inside Train.cpp
    bool Train::transfer(const Train& from) {
        if (!validState || !from.validState) {
            return false; // One of the trains is in an invalid state
        }

        // Combine the names of both trains
        std::string combinedName = name + ", " + from.name;

        // Calculate the available space in the current train
        int availableSpace = maxPassengers - passengers;

        // Check if there is enough space to transfer passengers
        if (from.passengers <= availableSpace) {
            // Update the current train's name and passenger count
            name = combinedName;
            passengers += from.passengers;

            // Update the total passengers boarded
            totalPassengersBoarded += from.passengers;

            return true;
        }
        else {
            return false; // Not enough space to transfer passengers
        }
    }

    const std::string& Train::getName() const {
        return name;
    }

    int Train::getPassengers() const {
        return passengers;
    }

    int Train::getMaxPassengers() const {
        return maxPassengers;
    }
}
