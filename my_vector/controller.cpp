//
// Created by Patryk Likus on 25/10/2022.
//

#include "controller.h"
#include "consoleUsage.h"

using namespace std;

void Controller::run() {
    unsigned short option, stopOption = static_cast<unsigned short>(options::stop), countOption = static_cast<unsigned short>(options::count);
    do {
        for (unsigned short i = 1; i < countOption; i++)
            cout << i << " - " << optionsStrList[i] << endl;
        cout << "0 - " << optionsStrList[0] << endl;

        option = getInputNumber<unsigned short>("Enter a option:", stopOption, countOption - 1);

        switch (option) {
        case static_cast<unsigned short>(options::stop): break;
        case static_cast<unsigned short>(options::push): push(); break;
        case static_cast<unsigned short>(options::pop): pop(); break;
        case static_cast<unsigned short>(options::find): find(); break;
        case static_cast<unsigned short>(options::erase): erase(); break;
        case static_cast<unsigned short>(options::load): load(); break;
        case static_cast<unsigned short>(options::save): save(); break;
        case static_cast<unsigned short>(options::clearAll): clearAll(); break;
        case static_cast<unsigned short>(options::displayAll): displayAll(); break;
        case static_cast<unsigned short>(options::modify): modify(); break;
        }
    } while (option != stopOption);
}

void Controller::push() {
    auto number = getInputNumber<int>("Enter number:");
    char name[512];
    getInputString("Enter name:", name, 512);
    auto x = getInputNumber<double>("Enter x:"), y = getInputNumber<double>("Enter y:");
    Node node(number, name, x, y);
    nodes.push(node);
}

void Controller::pop() {
    auto node = nodes.pop();
    if (node == nullptr)
        throwMess(static_cast<unsigned short>(mess::emptyVector));
    else
        cout << *node << endl;
}

void Controller::clearAll() {
    if (!nodes.last) {
        throwMess(static_cast<unsigned short>(mess::emptyVector));
        return;
    }
    cout << "clearing..." << endl;
    nodes.clearAll();
    cout << "objects properly removed." << endl;
}

void Controller::displayAll() {
    if (nodes.last)
        for (int i = 0; i < nodes.last; i++)
            cout << nodes[i] << endl;
    else
        throwMess(static_cast<unsigned short>(mess::emptyVector));
}

void Controller::load() {
    ifstream file("node.bin", ios::binary);
    if (file.is_open()) {
        file >> nodes;
        file.close();
    }
    else {
        throwErr(static_cast<unsigned short>(errors::fileNotOpened));
    }
}

void Controller::save() {
    if (!nodes.last) {
        throwMess(static_cast<unsigned short>(mess::emptyVector));
        return;
    }
    ofstream file("node.bin", ios::binary);
    if (file.is_open()) {
        file << nodes;
        file.close();
    }
    else {
        throwErr(static_cast<unsigned short>(errors::fileNotOpened));
    }
}

void Controller::modify() {
    if (!nodes.last) {
        throwMess(static_cast<unsigned short>(mess::emptyVector));
        return;
    }

    int i = getInputNumber<int>("Enter index:", 0, nodes.last - 1);
    cout << "NODE: " << endl << nodes[i] << endl;

    auto number = getInputNumber<int>("Enter number:");
    char name[512];
    getInputString("Enter name:", name, 512);
    auto x = getInputNumber<double>("Enter x:"), y = getInputNumber<double>("Enter y:");
    Node node(number, name, x, y);
    nodes[i] = node;
    cout << "UPDATED NODE: " << endl << nodes[i] << endl;
}

void Controller::erase() {
    if (!nodes.last) {
        throwMess(static_cast<unsigned short>(mess::emptyVector));
        return;
    }
    int i = getInputNumber<int>("Enter index:", 0, nodes.last - 1);
    cout << "NODE: " << endl << nodes[i] << endl;
    nodes.erase(&nodes[i]);
}

void Controller::find() {
    if (!nodes.last) {
        throwMess(static_cast<unsigned short>(mess::emptyVector));
        return;
    }
    auto number = getInputNumber<int>("Enter number:");
    Node key(number, "", 0, 0);
    nodes.find(key);
}