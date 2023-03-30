//
// Created by Patryk Likus on 26/10/2022.
//

#ifndef JIPP_PROJECT_MESSAGES_H
#define JIPP_PROJECT_MESSAGES_H
#include <iostream>
using namespace std;

enum class errors {
    invalidInput,
    fileNotOpened,
    indexOut,
    fileProblem,
    badAlloc,
};

string getErrMess(unsigned short errorNumber);
void throwErr(unsigned short errorNumber);

enum class mess {
    emptyVector,
    objNotFound,
};

string getMess(unsigned short messNumber);
void throwMess(unsigned short messNumber);

#endif //JIPP_PROJECT_MESSAGES_H