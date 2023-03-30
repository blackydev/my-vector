
#ifndef JIPP_PROJECT_CONSOLE_USAGE_H
#define JIPP_PROJECT_CONSOLE_USAGE_H
#include <iostream>
#include "messages.h"
using namespace std;

template<typename T>
T getInputNumber(const string& text) {
    cout << text << endl;
    T value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            throwErr(static_cast<unsigned short>(errors::invalidInput));
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
            return value;
    }
}

template<typename T>
T getInputNumber(const string& text, const T& min, const T& max) {
    cout << text << endl;
    while (true) {
        T value;
        cin >> value;
        if (cin.fail() || value < min || value > max) {
            throwErr(static_cast<unsigned short>(errors::invalidInput));
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
            return value;
    }
}

char* getInputString(const string& text, char* str, int strLength);

#endif //JIPP_PROJECT_CONSOLE_USAGE_H
