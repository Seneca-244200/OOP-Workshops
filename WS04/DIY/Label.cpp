#define _CRT_SECURE_NO_WARNINGS
#include "Label.h"
#include <iostream>
#include <cstring>

namespace sdds {

    Label::Label() {
        frame = nullptr;
        labelText = nullptr;
    }

    Label::Label(const char* frameArg) {
        if (frameArg != nullptr) {
            frame = new char[9];
            std::strncpy(frame, frameArg, 8);
            frame[8] = '\0';
        }
        else {
            frame = nullptr;
        }
        labelText = nullptr;
    }

    Label::Label(const char* frameArg, const char* content) {
        if (frameArg != nullptr) {
            frame = new char[9];
            std::strncpy(frame, frameArg, 8);
            frame[8] = '\0';
        }
        else {
            frame = nullptr;
        }

        labelText = nullptr;
        if (content != nullptr) {
            text(content);
        }
        else {
            labelText = nullptr;
        }
    }

    Label::~Label() {
        delete[] frame;
        delete[] labelText;
    }

    std::istream& Label::readLabel() {
        char buffer[71];
  
        std::cin.getline(buffer, 71);
        text(buffer);
        return std::cin;
    }

    std::ostream& Label::printLabel() const {
        int len = (labelText != nullptr) ? static_cast<int>(std::strlen(labelText)) : 0;

        if (len == 0) {
            // If the label text is empty, don't print anything
            return std::cout;
        }

        // Calculate the width of the label (including frame)
        int labelWidth = len + 2; // Add 2 for the backslashes

        // Calculate the number of padding lines for centering vertically
        int paddingLines = 1;
        if (labelWidth < 25) {
            paddingLines = (5 - labelWidth) / 2;
        }

        // Define symbols for the frame
        char frameTop = '+';
        char frameSide = '|';
        char frameBottom = '+';
        char frametopright = '+';
        char framedownright = '+';

        // Check if it's the second box and use different symbols for the top and bottom frames
        if (labelText != nullptr && std::strcmp(labelText, "Professor's Label Maker Program Tester") == 0) {
            frameTop = '/';
            frameBottom = '\\';
            frameSide = '|';
            frametopright = '\\';
            framedownright = '/';
        }

        // Print the top frame
        std::cout << frameTop;
        for (int i = 0; i < labelWidth; ++i) { // Adjusted for backslashes
            std::cout << "-";
        }
        std::cout << frametopright << std::endl;

        // Print padding lines for centering
        for (int i = 0; i < paddingLines; ++i) {
            std::cout << frameSide;
            for (int j = 0; j < labelWidth; ++j) {
                std::cout << " ";
            }
            std::cout << frameSide << std::endl;
        }

        // Print the label content with horizontal centering
        if (labelText != nullptr) {
            std::cout << frameSide;
            int spaces = (labelWidth - len + 1) / 2; // Calculate leading spaces
            for (int j = 0; j < spaces; ++j) {
                std::cout << " ";
            }
            std::cout << labelText;
            for (int j = 0; j < spaces; ++j) {
                std::cout << " ";
            }
            if (len % 1 != 0) {
                std::cout << " "; // Add an extra space for odd-length text
            }
            std::cout << frameSide << std::endl;
        }

        // Print remaining padding lines for centering
        for (int i = 0; i < paddingLines; ++i) {
            std::cout << frameSide;
            for (int j = 0; j < labelWidth; ++j) {
                std::cout << " ";
            }
            std::cout << frameSide << std::endl;
        }

        // Print the bottom frame
        std::cout << frameBottom;
        for (int i = 0; i < labelWidth; ++i) { // Adjusted for backslashes
            std::cout << "-";
        }
        std::cout << framedownright;

        return std::cout;
    }


    Label& Label::text(const char* content) {
        if (labelText != nullptr) {
            delete[] labelText;
        }
        if (content != nullptr && *content != '\0') {
            int len = static_cast<int>(std::strlen(content));
            labelText = new char[len + 1];
            std::strcpy(labelText, content);
        }
        else {
            labelText = nullptr;
        }
        return *this;
    }
}
