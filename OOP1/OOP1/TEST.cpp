//
//  Assigned by:
//
//  File Name:        TEST.cpp
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Collection.cpp, Collection.h
//

#include <iostream>
#include "Circle.h"
#include "Collection.h"
#include "Point.h"
using namespace std;

int main() {
    Collection g(4, 3, 2, 0);               // Create a collection
    cout << "-- before setColor(2) --" << endl;
    g.print();                          // Print the collection
    Point p(5, 1);                       // Create a point
    g.getCircleAt(p).setColor(2);             // Set different color to the returned circle
    cout << "-- after setColor(2) --" << endl;
    g.print();
    return 0;
}
