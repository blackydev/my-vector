#include "consoleUsage.h"

char *getInputString(const string& text, char * str, int strLength) {
    cout << text << endl;
    while (true) {
        cin.ignore();
        cin.getline(str, strLength);
        if (cin.fail() || !str[0]) {
            throwErr(static_cast<unsigned short>(errors::invalidInput));
            cin.clear();
        }
        else
            return str;
    }
}