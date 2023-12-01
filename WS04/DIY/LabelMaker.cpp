#define _CRT_SECURE_NO_WARNINGS
#include "LabelMaker.h"
#include <iostream>




namespace sdds { 

    LabelMaker::LabelMaker(int noOfLabels) {
        numberOfLabels = noOfLabels;
        labels = new Label[noOfLabels];
    }

    void LabelMaker::readLabels() {
           std:: cout << "Enter " << numberOfLabels << " labels:" << std:: endl;
        for (int i = 0; i < numberOfLabels; ++i) {
            std :: cout << "Enter label number " << i + 1 << std::  endl;
            std::cout << "> ";
            labels[i].readLabel();
        }
    }

void LabelMaker::printLabels() {
    for (int i = 0; i < numberOfLabels; ++i) {
        labels[i].printLabel();
        if (i < numberOfLabels - 1) {
            // Add a blank line between labels
            std::cout << std::endl;
        }
    }
}

LabelMaker::~LabelMaker() {
    delete[] labels;
    std::cout << std::endl;
}
}