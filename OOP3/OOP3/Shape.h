//
//  Assigned by:
//
//  File Name:        Shape.h
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#ifndef Shape_h
#define Shape_h

class Shape {                               // "Shape" class - abstract
public:
    virtual ~Shape() {};                    // Virtual destructor for the class
    virtual double getArea() const = 0;     // Pure virtual function
    virtual double getPerim() const = 0;    // Pure virtual function
};

#endif /* Shape_h */
