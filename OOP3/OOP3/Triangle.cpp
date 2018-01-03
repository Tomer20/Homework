//
//  Assigned by:
//
//  File Name:        Triangle.cpp
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#include <math.h>
#include "Triangle.h"

Triangle::Triangle(Point const &a, Point const &b, Point const &c) {
    this->num_of_points = 3;
    this->point_array = new Point[this->num_of_points];
    this->point_array[0] = Point(a.getX(), a.getY());
    this->point_array[1] = Point(b.getX(), b.getY());
    this->point_array[2] = Point(c.getX(), c.getY());
}

// Calculate triangle's area using Heron’s formula
double Triangle::getArea() const {
    double side_a, side_b, side_c, half_perim, area;
    side_a = getDistance(this->point_array[0], this->point_array[1]);
    side_b = getDistance(this->point_array[1], this->point_array[2]);
    side_c = getDistance(this->point_array[2], this->point_array[0]);
    half_perim = this->getPerim() / 2;
    area = sqrt(half_perim * (half_perim - side_a) * (half_perim - side_b) * (half_perim - side_c));
    return area;
}
