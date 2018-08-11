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

    const int bs = 30; // buffer size. Must be as big as the biggest layer. 
    double currentIn[bs];      // <-- pre-allocated, to be filled later
    double currentBetween[bs]; // <-- pre-allocated, to be filled later
    double currentOut[bs];     // <-- pre-allocated, to be filled later

    // putting input into currentInput
    for(int i = 0; i < bs; i++) currentIn[i] = input[i];

    for(unsigned l = 0; l < layers.size(); l++) {
        Layer& layer = layers[l];
        Connection& conn = connections[l];
        
        conn.propagate(currentIn, currentBetween);
        layer.evaluate(currentBetween, currentOut);

        // copying out to in, so that operations on out wont affect in. TODO: maybe i should do a pointerswap here?
        for(int i = 0; i < bs; i++) {
            currentIn[i] = currentOut[i];
            currentOut[i] = 0.0;
        }
    }

    // putting results in the preallocated output array
    for(int i = 0; i < bs; i++) output[i] = currentOut[i];
};


void NN::backprop(std::vector< std::vector<double> > inputs, std::vector< std::vector<double> > outputs) {
}
