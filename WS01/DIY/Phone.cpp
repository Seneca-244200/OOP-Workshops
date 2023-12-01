#include <iostream>
#include <fstream>
#include <string>
#include "Phone.h"
#include "cStrTools.h"

using namespace std;
using namespace sdds;

void sdds::phoneDir(const char* programTitle, const char* fileName)
{
    ifstream file(fileName);
    if (!file) {
        cout << "Broken Phone Book phone direcotry search" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "badDataFile.txt file not found!" << endl;
        cout << "Thank you for using Broken Phone Book directory." << endl;
        return;
    }

    char partialName[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    char areaCode[MAX_PHONE_LEN];
    char prefix[MAX_PHONE_LEN];
    char number[MAX_PHONE_LEN];

    cout << "Star Wars phone direcotry search" << endl; // Program title provided as an argument
    cout << "-------------------------------------------------------" << endl;

    while (true) {
        cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
        cout << "> ";
        cin.getline(partialName, MAX_NAME_LEN); // Read the partial name

        if (partialName[0] == '!') {
            break;
        }

        // Convert the partial name to lowercase
        char lowercasePartialName[MAX_NAME_LEN];
        toLowerCaseAndCopy(lowercasePartialName, partialName);

        file.clear(); // Clear any EOF flags
        file.seekg(0); // Move the file pointer to the beginning

        while (file >> ws && !file.eof()) {
            file.getline(name, MAX_NAME_LEN, '\t');

            // Convert the name in the data file to lowercase
            char lowercaseName[MAX_NAME_LEN];
            toLowerCaseAndCopy(lowercaseName, name);

            file.getline(areaCode, MAX_PHONE_LEN, '\t');
            file.getline(prefix, MAX_PHONE_LEN, '\t');
            file.getline(number, MAX_PHONE_LEN, '\n');

            if (strStr(lowercaseName, lowercasePartialName) != nullptr) {
                cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl;
              
            }
        }
    }

    file.close();
    cout << "Thank you for using " << programTitle << " directory." << endl;
}
