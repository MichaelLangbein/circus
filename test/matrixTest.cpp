#define BOOST_TEST_MODULE MatrixTest
#include <iostream>
#include "matrix.hpp"
#include <boost/test/included/unit_test.hpp>


void printVector(Vector& v) {
    int S = v.getSize();
    std::cout << " ----- begin vector ----" << std::endl;
    for (int i = 0; i < S; i ++ ) {
        std::cout << v.get(i) << std::endl;
    }
    std::cout << " ----- end vector -----" << std::endl;
}

void printMatrix(Matrix& m) {
    int R = m.getRows();
    int C = m.getCols();
    std::cout << " ----- begin matrix ----" << std::endl;
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            double val = m.get(r, c);
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << " ----- end matrix -----" << std::endl;
}




BOOST_AUTO_TEST_CASE( vector_test ) {

    int S = 3;
    Vector v(S);
    for (int i = 0; i < S; i++) {
        v.set(i, 1.0);
    }

    Vector u(S);
    for (int i = 0; i < S; i++) {
        v.set(i, 1.0);
    }

    double innerPrd = v * u;
    printf("Inner prod: %d \n", innerPrd);

    Vector sumV = v + u;
    printVector(sumV);
}

BOOST_AUTO_TEST_CASE( matrix_test ) {

    int R = 2;
    int C = 3;
    Matrix m(R, C);
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            m.set(r,c, 1.0);
        }
    }

    Matrix n(R, C);
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            n.set(r,c, 1.0);
        }
    }

    Matrix o(C, R);
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            n.set(r,c, 1.0);
        }
    }

    Vector v(C);
    for(int c = 0; c < C; c++) {
        v.set(c, 1.0);
    }

    Matrix sum = n + m;
    printMatrix(sum);

    Matrix prd = n *  o;
    printMatrix(prd);

    Vector pv = m * v;
    printVector(pv);
}
