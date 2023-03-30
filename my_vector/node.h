#ifndef JIPP_PROJECT_NODE_H
#define JIPP_PROJECT_NODE_H
#include <iostream>
#include <fstream>
#include "point.h"
using namespace std;

class Node : public Point
{
public:
    Node(const int& number_, const char* name_, const double& x_, const double& y_);
    Node() : Point() { number = 0; };

    Node& operator=(const Node& node);
    friend bool operator==(const Node& n1, const Node& n2);


    friend ostream& operator<<(ostream& stream, const Node& n);
    friend ofstream& operator<<(ofstream& stream, const Node& n);


    friend istream& operator>>(istream& stream, Node& n);
    friend ifstream& operator>>(ifstream& stream, Node& n);

private:
    int number;   // number of node
    char name[512];  // name of node
};


#endif //JIPP_PROJECT_NODE_H