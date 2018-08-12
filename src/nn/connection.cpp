#include <string>
#include <sstream>
#include "connection.hpp"



Connection::Connection(int in, int out) : weightMatrix(out, in) {
}


Vector Connection::propagate(const Vector& dataIn) {
    if (dataIn.getSize() != getInSize()) throw "Wrong input size!";
    Vector dataOut = weightMatrix * dataIn;
    return dataOut;
}


void Connection::setWeight(int r, int c, double val) {
    weightMatrix.set(r,c,val);
}


int Connection::getInSize() {
    return weightMatrix.getCols();
}


int Connection::getOutSize() {
    return weightMatrix.getRows();
}