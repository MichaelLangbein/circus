#ifndef nn_h
#define nn_h



#include <vector>
#include "layer.hpp"
#include "connection.hpp"


class NN {
    private:
        std::vector<Layer> layers;
        std::vector<Connection> connections;

    public:
        NN(std::vector<int> layerSizes);
        Vector evaluate(const Vector& input);
};


#endif