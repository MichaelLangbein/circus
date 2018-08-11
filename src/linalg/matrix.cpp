#include <stdlib.h>
#include <stdio.h>
#include "matrix.hpp"


Matrix::Matrix (int rows, int cols) : rows(rows), cols(cols) {
    vals = (double**) malloc(sizeof(double*) * rows);
    for(int r = 0; r<rows; r++) {
        vals[r] = (double*) malloc(sizeof(double) * cols);
        for(int c = 0; c<cols; c++) {
            vals[r][c] = 0.0;
        }
    }
}


// Copy constructor. Called when: 
// Matrix m1(10, 12); 
// Matrix m2 = m1;
Matrix::Matrix(const Matrix& source) {
    rows = source.rows;
    cols = source.cols;
    vals = (double**) malloc( sizeof(double*) * rows);
    for (int r = 0; r < rows; r++) {
        vals[r] = (double*) malloc( sizeof(double) * cols);
        for(int c = 0; c < cols; c++) {
            vals[r][c] = source.get(r,c);
        }
    }
}

// Assignment operator. Called when:
// Matrix m1(10, 12);
// Matrix m2(11, 11);
// m2 = m1;
Matrix& Matrix::Matrix::operator= (const Matrix& source) {
    // step 1: delete own values
    for(int r = 0; r < rows; r++) {
        free(vals[r]);
    }
    free(vals);

    // step 2: copy sources values to self
    rows = source.rows;
    cols = source.cols;
    vals = (double**) malloc( sizeof(double*) * rows);
    for (int r = 0; r < rows; r++) {
        vals[r] = (double*) malloc( sizeof(double) * cols);
        for(int c = 0; c < cols; c++) {
            vals[r][c] = source.get(r,c);
        }
    }
    return *this;
}


Matrix Matrix::operator+ (const Matrix& other) {
    if( other.getCols() != getCols() || other.getRows() != getRows()) throw "Matrices must be of equal size!";

    Matrix newMatrix(getRows(), getCols());

    for(int r = 0; r < getRows(); r++) {
        for (int c = 0; c < getCols(); c++) {
            double sum = get(r, c) + other.get(r, c);
            newMatrix.set(r, c, sum);
        }
    }

    return newMatrix;
}


Matrix Matrix::operator* (const Matrix& other) {
    if(getCols() != other.getRows()) throw "Second matrix must have as many rows as first has cols!";

    Matrix newMatrix(getRows(), other.getCols());

    for(int r = 0; r < newMatrix.getRows(); r++) {
        for (int c = 0; c < newMatrix.getCols(); c++) {
            // TODO
        }
    }

    return newMatrix;
}


Vector Matrix::operator* (const Vector& vec) {
    if(getCols() != vec.getSize()) throw "Vector must be as long as matrix has cols!";

    Vector newVec(getRows());

    for(int r = 0; r < getRows(); r++) {
        double sum = 0; 
        for (int c = 0; c < getCols(); c++) {
            sum += get(r, c) * vec.get(c);
        }
        newVec.set(r, sum);
    }

    return newVec;
}

Matrix::~Matrix() {
    for(int r = 0; r < getRows(); r++) {
        free(vals[r]);
    }
    free(vals);
}


int Matrix::getRows() const {
    return rows;
}


int Matrix::getCols() const {
    return cols;
}

double Matrix::get(int r, int c) const {
    if(r >= getRows() || c >= getCols() ) throw "Index out of bounds!";
    return vals[r][c];
}

void Matrix::set(int r, int c, double val) {
    if(r >= getRows() || c >= getCols() ) throw "Index out of bounds!";
    vals[r][c] = val;
}