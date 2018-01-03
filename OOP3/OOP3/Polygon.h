//
//  Assigned by:
//
//  File Name:        Polygon.h
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#ifndef Polygon_h
#define Polygon_h

#include "Shape.h"
#include "Point.h"

// Abstract class that inherits from "Shape" class.
class Polygon : public Shape {
public:
    ~Polygon();             // Destructor for the "Point *point_array"
    int getNumOfPoints() const;
    double getPerim() const;
protected:
    int num_of_points;      // This variable is defined according to shape's size
    Point *point_array;     // Array to store all shape's points
};

#endif /* Polygon_h */
