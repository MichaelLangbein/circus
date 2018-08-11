#include <stdlib.h>
#include <stdio.h>
#include "matrix.hpp"


Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    vals = (double**) malloc( sizeof(double*) * rows);
    for(int r = 0; r < rows; r++) {
        vals[r] = (double*) malloc( sizeof(double) * cols); 
        for(int c = 0; c < cols; c++) {
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
Matrix& Matrix::operator= (const Matrix& source) {
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


Matrix::~Matrix() {
    for(int r = 0; r < rows; r++) {
        free(vals[r]);
    }
    free(vals);
}


void Matrix::mult(double* dataIn, double* dataOut) {
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            dataOut[r] += vals[r][c] * dataIn[c];
        }
    }
}

double Matrix::get(int r, int c) const {
    return vals[r][c];
}


