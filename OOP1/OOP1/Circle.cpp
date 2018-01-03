//
//  Assigned by:
//
//  File Name:        Circle.cpp
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Collection.cpp, Collection.h
//

#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(int x, int y, int r, int color)      // Constructor
: center(x, y), radius(r), color(color) {}

int Circle::getColor() const { return this->color; }    // Return circle's color

void Circle::setColor(int color) { this->color = color; }   // Set circle's color

bool Circle::contains(const Point &p) const {
    // Check if a circle containes a given point using distance formula
    int x_square = (p.getX() - this->center.getX()) * (p.getX() - this->center.getX());
    int y_square = (p.getY() - this->center.getY()) * (p.getY() - this->center.getY());
    int radius_square = this->radius * this->radius;
    return (x_square) + (y_square) < radius_square ? true : false;
}

void Circle::print() const {
    // Print circle's attributes
    cout << "Circle: center = (" << this->center.getX() << ", " << this->center.getY() <<
    "), radius = " << this->radius << ", color = " << this->color << endl;
}
