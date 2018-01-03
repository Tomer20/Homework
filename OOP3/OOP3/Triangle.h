//
//  Assigned by:
//
//  File Name:        Triangle.h
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#ifndef Triangle_h
#define Triangle_h

#include "Polygon.h"

class Triangle : public Polygon {   // Inherits from "Polygon" class
public:
    Triangle(Point const &, Point const &, Point const &);
    double getArea() const;         // Implementation of pure virtual function
};

#endif /* Triangle_h */
