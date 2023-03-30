#include "messages.h"
#include <iostream>
using namespace std;

string getErrMess(unsigned short errorNumber) {
    switch (errorNumber) {
    case static_cast<unsigned short>(errors::invalidInput): return "Invalid input!";
    case static_cast<unsigned short>(errors::fileNotOpened): return "Unsuccessful opening of file.";
    case static_cast<unsigned short>(errors::indexOut): return "Index out of bounds";
    case static_cast<unsigned short>(errors::fileProblem): return "Problem with the file!";
    case static_cast<unsigned short>(errors::badAlloc): return "FATAL ERROR! Memory allocation failed.";
    default: return "Unexpected error.";
    }
}

void throwErr(unsigned short errorNumber) { cerr << getErrMess(errorNumber) << endl; }

string getMess(unsigned short messNumber) {
    switch (messNumber) {
    case static_cast<unsigned short>(mess::emptyVector): return "Vector is empty.";
    case static_cast<unsigned short>(mess::objNotFound): return "Object not found.";
    default: return "";
    }
}

void throwMess(unsigned short messNumber) { cout << getMess(messNumber) << endl; }