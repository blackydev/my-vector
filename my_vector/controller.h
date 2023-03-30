
#ifndef JIPP_PROJECT_CONTROLLER_H
#define JIPP_PROJECT_CONTROLLER_H
#include "vector.h"
#include "node.h"

using namespace std;

class Controller {
public:
    void run();
private:
    Vector<Node> nodes = Vector<Node>(2);
    enum class options {
        stop,
        push,
        pop,
        modify,
        erase,
        find,
        displayAll,
        clearAll,
        load,
        save,
        count
    };

    const string optionsStrList[static_cast<unsigned short>(options::count)] = {
            "stop",
            "push",
            "pop",
            "modify",
            "erase",
            "find",
            "display all",
            "clear all",
            "load",
            "save" };

    void push(),
        pop(),
        modify(),
        erase(),
        find(),
        displayAll(),
        clearAll(),
        load(),
        save();
};


#endif //JIPP_PROJECT_CONTROLLER_H
