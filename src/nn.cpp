#include "nn.hpp"
#include <stdio.h>


NN::NN(std::vector<int> layerSizes) {
    for(unsigned l = 1; l < layerSizes.size(); l++) {

        int lastSize = layerSizes[l-1];
        int currSize = layerSizes[l];        

        Connection conn(currSize, lastSize);
        connections.push_back(conn);        
        
        Layer layer(currSize);
        layers.push_back(layer);
    }    
}


void NN::evaluate(double* input, double* output) {

    double* currentIn = input; // <-- currentIn points to input
    double currentBetween[30]; // <-- pre-allocated, to be filled later
    double currentOut[30];     // <-- pre-allocated, to be filled later

    for(unsigned l = 0; l < layers.size(); l++) {
        Layer& layer = layers[l];
        Connection& conn = connections[l];
        
        conn.propagate(currentIn, currentBetween);
        layer.evaluate(currentBetween, currentOut);    
        
        currentIn = currentOut; // <--currentIn points to last output
    }

    // putting results in the preallocated output array
    for(int i = 0; i < oc; i++) {
        output[i] = currentOut[i];
    }
};


void NN::backprop(std::vector< std::vector<double> > inputs, std::vector< std::vector<double> > outputs) {
}
