//
//  Assigned by:
//
//  File Name:        Point.cpp
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Collection.cpp, Collection.h
//

#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int x, int y)
: x(x), y(y) {}

int Point::getX() const { return this->x; }

int Point::getY() const { return this->y; }

void Point::setX(int x) { this->x = x; }

void Point::setY(int y) { this->y = y; }

void Point::print() const {
    // Print point's attributes
    cout << "Point: (" << this->x << ", " << this->y << ")" << endl;
}
