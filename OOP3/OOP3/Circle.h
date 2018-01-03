//
//  Assigned by:
//
//  File Name:        Circle.h
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#ifndef Circle_h
#define Circle_h

#include "Shape.h"
#include "Point.h"

static const double pi = 3.14159265359;

class Circle : public Shape {       // Inherits from "Shape" class
public:
    Circle(Point const &, double);
    double getArea() const;         // Implementation of pure virtual function
    double getPerim() const;        // Implementation of pure virtual function
private:
    Point center;
    double radius;
};

#endif /* Circle_h */
