//
//  Assigned by:
//
//  File Name:        Collection.hpp
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Collection.cpp, Collection.h
//

#ifndef Collection_h
#define Collection_h

#include <stdio.h>
#include "Point.h"
#include "Circle.h"

class Collection {
public:
    Collection(int radius, int width, int height, int color);
    ~Collection();
    Circle &getCircleAt(const Point &p);
    void print() const;
private:
    int count;
    Circle **circles;
};

#endif /* Collection_h */
