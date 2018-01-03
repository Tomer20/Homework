//
//  Assigned by:
//
//  File Name:        Collection.cpp
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Collection.cpp, Collection.h
//

#include "Collection.h"
#include <iostream>
using namespace std;

Collection::Collection(int radius, int width, int height, int color) {
    // Collection constructor
    int i = 0, j = 0, k = 0, gap = radius * 2;
    this->count = width * height;   // Size of collection
    this->circles = new Circle*[this->count];   // Allocate memory for circles array
    while (i < height){
        while (j < width){
            circles[k] = new Circle(j * gap, i * gap, radius, color);
            j++;
            k++;
        }
        j = 0;
        i++;
    }
}

Collection::~Collection() {
    // Destructor free the allocated memory for the array
    int i;
    for (i = 0; i < this->count; i++) {
        delete this->circles[i];
    }
    delete [] this->circles;
}

Circle &Collection::getCircleAt(const Point &p) {
    int i;
    for (i = 0; i < this->count; i++) {
        if (this->circles[i]->contains(p)) {
            return *(this->circles[i]); // Return the matched circle
        }
    }
    cout << "The given point was not found in any circle of the collection." << endl <<
    "The first circle is returned instead." << endl;
    return *(this->circles[0]);
}

void Collection::print() const {
    // Print the collection
    int i;
    for (i = 0; i < this->count; i++) {
        this->circles[i]->print();
    }
}
