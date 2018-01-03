//
//  Assigned by:
//
//  File Name:        Matrix.cpp
//  Files in project: TEST.cpp, Matrix.cpp, Matrix.h
//

#include "Matrix.h"

Matrix::Matrix(int rows, int cols)
: rows(rows), cols(cols) {
    int i, j;
    this->matrix = new int*[rows];
    for (i = 0; i < rows; i ++) {
        this->matrix[i] = new int[cols];
    }
    // Initialize matrix with zeros:
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            this->matrix[i][j] = 0;
        }
    }
}

Matrix::~Matrix() {
    int i;
    for (i = 0; i < this->rows; i ++) {
        delete this->matrix[i];
    }
    delete this->matrix;
}

int Matrix::getRows() const { return this->rows; }
int Matrix::getCols() const { return this->cols; }
void Matrix::setRows(int r) { this->rows = r; }
void Matrix::setCols(int c) { this->cols = c; }

int* &Matrix::operator[](int index) const { return this->matrix[index]; }

ostream &operator<<(ostream &os, const Matrix &m) {
    int i, j;
    for (i = 0; i < m.getRows(); i++) {
        for (j = 0; j < m.getCols(); j++) {
            os << " " << m[i][j];
        }
        os << endl;
    }
    return os;
}

Matrix &Matrix::operator+(Matrix const &m) const {
    int i, j;
    Matrix *result = new Matrix(this->rows, this->cols);
    for (i = 0; i < this->rows; i++) {
        for (j = 0; j < this->cols; j++) {
            result->matrix[i][j] = this->matrix[i][j] + m[i][j];
        }
    }
    return *result;
}

Matrix &Matrix::operator-() const {
    int i, j;
    Matrix *result = new Matrix(this->rows, this->cols);
    for (i = 0; i < this->rows; i++) {
        for (j = 0; j < this->cols; j++) {
            result->matrix[i][j] = this->matrix[i][j] * (-1);
        }
    }
    return *result;
}

Matrix &Matrix::operator-(Matrix const &m) const {
    int i, j;
    Matrix *result = new Matrix(this->rows, this->cols);
    for (i = 0; i < this->rows; i++) {
        for (j = 0; j < this->cols; j++) {
            result->matrix[i][j] = this->matrix[i][j] - m[i][j];
        }
    }
    return *result;
}

Matrix &Matrix::operator*(Matrix const &m) const {
    Matrix *result = new Matrix(this->rows, m.getCols());
    int i, j, k;
    if (this->cols != m.getRows()) {
        cout << "Matrices multiplication can be done only when (mat1->cols == mat2->rows)!" << endl;
    }
    else {
        for (i = 0; i < result->rows; i++) {
            for (j = 0; j < result->cols; j++) {
                result->matrix[i][j] = 0;
                for (k = 0; k < m.getRows(); k++) {
                    result->matrix[i][j] = result->matrix[i][j] + this->matrix[i][k] * m[k][j];
                }
            }
        }
    }
    return *result;
}

Matrix &Matrix::operator*(int num) const {
    Matrix *result = new Matrix(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            result->matrix[i][j] = this->matrix[i][j] * num;
        }
    }
    return *result;
}

Matrix &operator*(int num, Matrix const &m) {
    return m * num;
}
