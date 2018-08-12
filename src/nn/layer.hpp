#ifndef layer_h
#define layer_h


#include "matrix.hpp"

class Layer {
    private:
        int size;

    public:
        Layer(int size);
        int getSize();
        Vector evaluate(const Vector& dataIn);

};


#endif