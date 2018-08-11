#include <stdlib.h>
#include <stdio.h>
#include "vector.hpp"


Vector::Vector(int size) : size(size) {
    vals = (double*) malloc(sizeof(double) * size);
}


Vector::Vector(const Vector& source) {
    size = source.getSize();
    vals = (double*) malloc(sizeof(double) * size);
    for(int i = 0; i<size; i++) {
        vals[i] = source.get(i);
    }
}


Vector& Vector::operator=(const Vector& source) {
    size = source.getSize();

    free(vals);

    vals = (double*) malloc(sizeof(double) * size);
    for(int i = 0; i<size; i++) {
        vals[i] = source.get(i);
    }

    return *this;
}


Vector Vector::operator+(const Vector& other) {
    int S1 = getSize();
    int S2 = other.getSize();
    if(S1 != S2) throw "Vectors must be the same size!";

    Vector newVec(S1);
    for(int i = 0; i < S1; i++) {
        newVec.set(i, get(i) + other.get(i));
    }

    return newVec;
}

double Vector::operator*(const Vector& other) {
    int S1 = getSize();
    int S2 = other.getSize();
    if(S1 != S2) throw "Vectors must be the same size!";

    double innerProd = 0.0; 
    for(int i = 0; i < S1; i++) {
        innerProd += get(i) * other.get(i);
    }

    return innerProd;
}

Vector Vector::operator*(double scalar) {
    Vector newVec(*this); // <-- calling copy constructor
    for(int i = 0; i < getSize(); i++) {
        double newVal = scalar * get(i);
        newVec.set(i, newVal);
    }
    return newVec;
}


Vector::~Vector() {
    free(vals);
}


int Vector::getSize() const {
    return size;
}


void Vector::set(int pos, double val) {
    if(pos >= getSize()) throw "This vector is not that long!";
    vals[pos] = val;
}


double Vector::get(int pos) const {
    if(pos >= getSize()) throw "This vector is not that long!";
    return vals[pos];
};
