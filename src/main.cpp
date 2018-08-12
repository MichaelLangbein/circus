#include <stdio.h>
#include <string>
#include <vector>
#include "nn.hpp"



int main() {

    std::vector<int> layerSizes = {3, 4, 3};
    NN nn(layerSizes);
    
    Vector input(3);
    input[0] = 1;
    input[1] = 2;
    input[2] = 3;

    Vector output = nn.evaluate(input);

    for(int i = 0; i < 3; i++){
        printf("%f \n", output[i]);
    }

    return 0;
}

