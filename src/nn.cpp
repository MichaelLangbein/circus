#include "nn.hpp"
#include <stdio.h>


NN::NN(std::vector<int> layerSizes) {
    for(int s : layerSizes) {
        Connection c;
        Layer l;
        connections.push_back(c);        
        layers.push_back(l);
    }    
}

void NN::evaluate(double* input, double* output) {
    int L = layers.size();
    for(int l = 0; l < L; l++) {
        printf("now evaluating %i \n", l);
    }
};

void NN::backprop(std::vector< std::vector<double> > inputs, std::vector< std::vector<double> > outputs) {
}
