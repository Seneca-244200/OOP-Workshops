#ifndef LABEL_H
#define LABEL_H

#include <iostream>

namespace sdds { // Add the sdds namespace

    class Label {
    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();

        std::istream& readLabel();
        std::ostream& printLabel() const;
        Label& text(const char* content);

    private:
        char* frame;
        char* labelText;
    };

}
#endif // LABEL_H
