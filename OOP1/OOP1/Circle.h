//
//  Assigned by:
//
//  File Name:        Circle.h
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Collection.cpp, Collection.h
//

#ifndef Circle_h
#define Circle_h

#include <stdio.h>
#include "Point.h"

class Circle {
public:
    Circle(int x, int y, int r, int color);
    int getColor() const;
    void setColor(int color);
    bool contains(const Point &p) const;
    void print() const;
private:
    const Point center;
    int radius, color;
};

#endif /* Circle_h */
