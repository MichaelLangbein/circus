#include "matrix.hpp"


class Connection {
    private:
        Matrix weightMatrix;    

    public:
        Connection(int out, int in);
        int getInSize();
        int  getOutSize();
        Vector propagate(Vector& dataIn);

};
