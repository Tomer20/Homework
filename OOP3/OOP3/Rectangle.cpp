//
//  Assigned by:
//
//  File Name:        Rectangle.cpp
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#include "Rectangle.h"

Rectangle::Rectangle(Point const &a, Point const &b) {
    this->num_of_points = 4;
    this->point_array = new Point[this->num_of_points];
    this->point_array[0] = a;
    this->point_array[1] = Point(a.getY(), b.getX());
    this->point_array[2] = b;
    this->point_array[3] = Point(a.getX(), b.getY());
}

double Rectangle::getArea() const {
    double width, hieght;
    width = getDistance(this->point_array[0], this->point_array[1]);
    hieght = getDistance(this->point_array[1], this->point_array[2]);
    return width * hieght;
}
