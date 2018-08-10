#include <stdlib.h>
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

Matrix::~Matrix() {
    for(int r = 0; r < rows; r++) {
        free(vals[r]);
    }
    free(vals);
}


void Matrix::leftMult(double* dataIn, double* dataOut) {
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            dataOut[r] += vals[r][c] * dataIn[c];
        }
    }
}
