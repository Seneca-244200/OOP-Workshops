#ifndef LABELMAKER_H
#define LABELMAKER_H

#include "Label.h" // Include the header for Label

namespace sdds { // Add the sdds namespace

    class LabelMaker {
    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        ~LabelMaker();
        void printLabels();

    private:
        Label* labels;
        int numberOfLabels;
    };

} // Close the sdds namespace

#endif // LABELMAKER_H
