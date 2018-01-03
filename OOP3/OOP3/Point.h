//
//  Assigned by:
//
//  File Name:        Point.h
//  Files in project: TEST.cpp, Circle.cpp, Circle.h, Point.cpp,
//                    Point.h, Polygon.cpp, Polygon.h, Rectangle.cpp,
//                    Rectangle.h, Shape.h, Triangle.cpp, Triangle.h
//

#ifndef Point_h
#define Point_h

class Point {
public:
    Point();
    Point(int, int);
    ~Point();
    void setX(int);
    void setY(int);
    int getX() const;
    int getY() const;
    // Function to get distance between two points
    friend double getDistance(Point const &, Point const &);
private:
    int x;
    int y;
};

#endif /* Point_h */
