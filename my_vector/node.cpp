#include <iostream>
#include "messages.h"
#include "node.h"
using namespace std;

Node::Node(const int& number_, const char* name_, const double& x_, const double& y_) : Point(x_, y_) {
    number = number_;
    strcpy_s(name, 512, name_);
}

// OPERATOR'S OVERLOADING

Node& Node::operator=(const Node& node) {
    if (this == &node)  return *this; // guard self assignment
    strcpy_s(name, 512, node.name);
    number = node.number;
    x = node.x;
    y = node.y;
    return *this;
}

bool operator==(const Node& n1, const Node& n2) { return (n1.number == n2.number); }

// console
ostream& operator<<(ostream& stream, const Node& n) {
    return stream
        << "number: " << n.number << endl
        << "name  : " << n.name << endl
        << "x     : " << n.x << endl
        << "y     : " << n.y << endl;
}

istream& operator>>(istream& stream, Node& n) { return stream >> n.number >> n.x >> n.y >> n.name; }

// files
ofstream& operator<<(ofstream& stream, const Node& n) {
    ios::pos_type pos = stream.tellp();
    unsigned long long offset;
    stream.write(reinterpret_cast<const char*>(&n), static_cast<streamsize>(sizeof(Node)));
    offset = stream.tellp() - pos;
    if (stream.bad() || stream.fail() || offset != sizeof(Node))
        throwErr(static_cast<unsigned short>(errors::fileProblem));

    return stream;
}


ifstream& operator>>(ifstream& stream, Node& n) {
    stream.read(reinterpret_cast<char*>(&n), static_cast<streamsize>(sizeof(Node)));
    if (stream.bad() || stream.fail() || stream.gcount() != sizeof(Node))
        throwErr(static_cast<unsigned short>(errors::fileProblem));

    return stream;
}