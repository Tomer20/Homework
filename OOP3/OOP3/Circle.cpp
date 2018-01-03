//
//  Assigned by:
//
//  File Name:        Circle.cpp
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#include "Circle.h"

Circle::Circle(Point const &p, double radius)
: center(p.getX(), p.getY()), radius(radius) {}

double Circle::getArea() const { return pi * (this->radius * this->radius); }
double Circle::getPerim() const { return 2 * pi * this->radius; }
