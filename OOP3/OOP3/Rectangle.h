//
//  Assigned by:
//
//  File Name:        Rectangle.h
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#ifndef Rectangle_h
#define Rectangle_h

#include "Polygon.h"

class Rectangle : public Polygon {   // Inherits from "Polygon" class
public:
    Rectangle(Point const &, Point const &);
    double getArea() const;          // Implementation of pure virtual function
};

#endif /* Rectangle_h */
