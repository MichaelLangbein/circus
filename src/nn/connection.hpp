#include "matrix.hpp"


class Connection {
    private:
        int inCount;
        int outCount;
        Matrix weightMatrix;    

    public:
        Connection(int out, int in);

        Vector& propagate(Vector& dataIn);

};
