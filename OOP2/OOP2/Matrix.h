//
//  Assigned by:
//
//  File Name:        Matrix.h
//  Files in project: TEST.cpp, Matrix.cpp, Matrix.h
//

#ifndef Matrix_h
#define Matrix_h

#include <stdio.h>
#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **matrix;
public:
    Matrix(int, int);
    ~Matrix();
    int getRows() const;
    int getCols() const;
    void setRows(int);
    void setCols(int);
    int* &operator[](int) const;
    friend ostream &operator << (ostream &, Matrix const &);

    Matrix &operator+(Matrix const &) const ;         // Matrix + Matrix
    
    Matrix &operator-() const;                        // -Matrix
    Matrix &operator-(Matrix const &) const;          // Matrix - Matrix
    
    Matrix &operator*(Matrix const &) const;          // Matrix * Matrix
    Matrix &operator*(int) const;                     // Matrix * Number
    friend Matrix &operator*(int, Matrix const &);    // Number * Matrix
};

#endif /* Matrix_h */
