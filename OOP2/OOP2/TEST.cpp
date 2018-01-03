//
//  Assigned by:
//
//  File Name:        TEST.cpp
//  Files in project: TEST.cpp, Matrix.cpp, Matrix.h
//

#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    cout << "Matrix class contains these features:\n" <<
    "1. Addition:\n" <<
    "\ta. Matrix + Matrix\n" <<
    "2. Subtraction:\n" <<
    "\ta. Matrix - Matrix\n" <<
    "3. Multiplication:\n" <<
    "\ta. Matrix * Matrix\n" <<
    "\tb. Matrix * Integer\n" <<
    "\tc. Integer * Matrix\n" <<
    "4. Opposite matrix (-matrix)\n" <<
    "5. Access matrix attributes using operator []\n" <<
    "6. Print matrix using operator <<\n\n" <<
    "Here is an example run:" << endl;
    Matrix m(2, 2);
    m[0][0] = 2;
    m[1][1] = 2;
    cout << m << endl;
    m = m;
    const Matrix s = -m;
    cout << m << endl << s << endl;
    m = s + 2 * -m * m * 2 - s;
    cout << m << endl << s << endl;
    cout << s[1][1] << endl;
    return 0;
}
