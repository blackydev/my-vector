#ifndef JIPP_PROJECT_POINT_H
#define JIPP_PROJECT_POINT_H


class Point {
public:
    Point(const double& x_, const double& y_) { x = x_; y = y_; }
    Point() { x = 0; y = 0; }
protected:
    double x, y;
};


#endif //JIPP_PROJECT_POINT_H