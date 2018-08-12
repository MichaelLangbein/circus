#ifndef connection_h
#define connection_h



#include "matrix.hpp"


class Connection {
    private:
        Matrix weightMatrix;    

    public:
        Connection(int in, int out);
        int getInSize();
        int  getOutSize();
        Vector propagate(const Vector& dataIn);
        void setWeight(int r, int c, double val);

};



#endif