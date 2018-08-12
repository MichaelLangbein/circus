#include "connection.hpp"



Connection::Connection(int out, int in) : weightMatrix(out, in) {
}

Vector Connection::propagate(Vector& dataIn) {
    if (dataIn.getSize() != getInSize()) throw "Wrong input size!";
    Vector dataOut = weightMatrix * dataIn;
    return dataOut;
}

int Connection::getInSize() {
    return weightMatrix.getCols();
}

int Connection::getOutSize() {
    return weightMatrix.getRows();
}