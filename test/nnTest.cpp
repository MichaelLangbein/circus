#define BOOST_TEST_MODULE NNTest
#include <iostream>
#include <string>
#include "connection.hpp"
#include "layer.hpp"
#include "nn.hpp"
#include <boost/test/included/unit_test.hpp>


void printVector(Vector& v, std::string descr = "") {
    int S = v.getSize();
    std::cout << " ----- begin vector: " << descr <<  " ----" << std::endl;
    for (int i = 0; i < S; i ++ ) {
        std::cout << v.get(i) << std::endl;
    }
    std::cout << " ----- end vector -----" << std::endl;
}

void printMatrix(Matrix& m, std::string descr = "") {
    int R = m.getRows();
    int C = m.getCols();
    std::cout << " ----- begin matrix: " << descr <<  " ----" << std::endl;
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            double val = m.get(r, c);
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << " ----- end matrix -----" << std::endl;
}




BOOST_AUTO_TEST_CASE( connection_test ) {  

    Connection conn(2, 3);
    
    Vector input(2);
    input[0] = 1;
    input[1] = 2;

    Vector output = conn.propagate(input);
    printVector(output);
}

BOOST_AUTO_TEST_CASE ( layer_test ) {

    Layer l(3);
    Vector input(3);
    input[0] = 0;
    input[1] = 1;
    input[2] = 2;

    Vector output = l.evaluate(input);
    printVector(output, "evaluation of [0,1,2]");

}


BOOST_AUTO_TEST_CASE ( nn_test ) {

    std::vector<int> layerSizes = {2,3,2};
    NN nn(layerSizes);

    Vector input(2);
    input[0] = 1;
    input[1] = 2;

    Vector output = nn.evaluate(input);
    printVector(output, "output of evaluation");
}