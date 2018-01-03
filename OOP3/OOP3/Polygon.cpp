//
//  Assigned by:
//
//  File Name:        Polygon.h
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#include "Polygon.h"

Polygon::~Polygon() {
    delete [] this->point_array;    // Delete the array of points
}

int Polygon::getNumOfPoints() const { return this->num_of_points; }

double Polygon::getPerim() const {
    // Return sum of all sides of the shape
    double perimeter = 0;
    for (int i = 0; i < this->getNumOfPoints() - 1; i++) {
        perimeter += getDistance(this->point_array[i], this->point_array[i+1]);
    }
    perimeter += getDistance(this->point_array[this->getNumOfPoints()-1], this->point_array[0]);
    return perimeter;
}
