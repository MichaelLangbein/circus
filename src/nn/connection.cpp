#include "connection.hpp"



Connection::Connection(int out, int in) : inCount(in), outCount(out), weightMatrix(in, out) {
}

Vector& Connection::propagate(Vector& dataIn) {
    if (dataIn.getSize() != inCount) throw "Wrong input size!";
    Vector result = weightMatrix * dataIn;
    return result;
}

