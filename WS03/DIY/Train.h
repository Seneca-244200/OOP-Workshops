#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>

namespace sdds {
    const int MIN_TIME = 700;
    const int MAX_TIME = 1576;

    class Train {
        std::string name;
        int passengers;
        int maxPassengers;
        int departureTime;
        bool validState;
        int totalPassengersBoarded;

    public:
        void initialize();
        void set(const char* trainName, int maxPass, int departTime);
        void set(int maxPass, int departTime);
        bool isInvalid() const;
        int getDepartureTime() const;
        void display() const;
        bool load(int& notBoarded);
        bool updateDepartureTime();
        void finalize();

        // New member function declarations for transfer and related functionalities
// Inside Train.h
        bool transfer(const Train& from);
        const std::string& getName() const;
        int getPassengers() const;
        int getMaxPassengers() const;
    };
}

#endif
