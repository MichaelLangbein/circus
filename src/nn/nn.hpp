#include <vector>
#include "layer.hpp"
#include "connection.hpp"


class NN {
    private:
        std::vector<Layer> layers;
        std::vector<Connection> connections;

    public:
        NN(std::vector<int> layerSizes);
        void evaluate(double* input, double* output);
        void backprop(std::vector< std::vector<double> > inputs, std::vector< std::vector<double> > outputs);
};
