#include <stdio.h>
#include <string>
#include <vector>
#include "nn.hpp"



int main() {

    std::vector<int> layerSizes = {3, 4, 3};
    NN nn(layerSizes);
    
    double input[3] = {1.1, 4.1, 2.4};
    double output[3] = {1, 1, 1};
    nn.evaluate(input, output);

    for(int i = 0; i < 3; i++){
        printf("%f \n", output[i]);
    }

    return 0;
}

