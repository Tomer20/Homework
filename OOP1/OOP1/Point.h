//
//  Assigned by:
//
//  File Name:        Point.h
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Collection.cpp, Collection.h
//

#ifndef Point_h
#define Point_h

#include <stdio.h>

class Point {
public:
    Point(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void print() const;
private:
    int x, y;
};

#endif /* Point_h */
