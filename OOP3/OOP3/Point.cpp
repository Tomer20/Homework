//
//  Assigned by:
//
//  File Name:        Point.cpp
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#include <math.h>
#include "Point.h"

Point::Point() {}

Point::Point(int x, int y)
: x(x), y(y) {}

Point::~Point() {}

void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }
int Point::getX() const { return this->x; }
int Point::getY() const { return this->y; }

// Get distance according to distance formula
double getDistance(Point const &p1, Point const &p2) {
    return sqrt(pow((double) p1.getX() - p2.getX(), 2) +
                pow((double) p1.getY() - p2.getY(), 2));
}
