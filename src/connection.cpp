#include "connection.hpp"



Connection::Connection(int out, int in) : inCount(in), outCount(out), weightMatrix(in, out) {
}

void Connection::propagate(double* dataIn, double* dataOut) {
    weightMatrix.leftMult(dataIn, dataOut);
}

