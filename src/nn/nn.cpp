#include "nn.hpp"
#include <iostream>
#include <stdio.h>


NN::NN(std::vector<int> layerSizes) {
    for(unsigned l = 1; l < layerSizes.size(); l++) {

        int lastSize = layerSizes[l-1];
        int currSize = layerSizes[l];        

        Connection conn(lastSize, currSize);
        connections.push_back(conn);        
        
        Layer layer(currSize);
        layers.push_back(layer);
    }    
}


Vector NN::evaluate(const Vector& input) {

    Vector currentInput(input);
    Vector currentBetween(input);
    Vector currentOutput(input);

    for(unsigned l = 0; l < layers.size(); l++) {

        Layer& layer = layers[l];
        Connection& conn = connections[l];
        
        currentBetween = conn.propagate(currentInput);
        currentOutput = layer.evaluate(currentBetween);
        
        currentInput = currentOutput;
    }

    return currentOutput;
};
