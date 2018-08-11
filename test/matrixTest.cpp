#define BOOST_TEST_MODULE MatrixTest
#include <iostream>
#include <string>
#include "matrix.hpp"
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




BOOST_AUTO_TEST_CASE( vector_test ) {

    int S = 3;
    Vector v(S);
    for (int i = 0; i < S; i++) {
        v[i] = 1.0;
    }
    printVector(v, "Testing if [] operator worked.");
    BOOST_ASSERT(v[0] == 1);

    Vector u(S);
    for (int i = 0; i < S; i++) {
        u[i] = 1.0;
    }

    double innerPrd = v * u;
    printf("Inner prod: %f \n", innerPrd);
    BOOST_ASSERT(innerPrd == 3);

    Vector sumV = v + u;
    printVector(sumV,  "sum of v and u");
    BOOST_ASSERT(sumV[0] == 2);

    Vector scaledV = v * 2;
    printVector(scaledV, "v * 2");
    BOOST_ASSERT(scaledV[0] == 2);
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
    for(int r = 0; r < C; r++) {
        for(int c = 0; c < R; c++) {
            o.set(r,c, 1.0);
        }
    }

    Vector v(C);
    for(int c = 0; c < C; c++) {
        v.set(c, 1.0);
    }

    Matrix sum = n + m;
    printMatrix(sum, "sum of m and n");
    BOOST_ASSERT(sum.get(1, 1) == 2);

    Matrix prd = n *  o;
    printMatrix(prd, "prod of n and o");
    BOOST_ASSERT(prd.getRows() == 2);
    BOOST_ASSERT(prd.getCols() == 2);
    BOOST_ASSERT(prd.get(1, 0) == 3);

    Vector pv = m * v;
    printVector(pv, "matrix - vector product.");
    BOOST_ASSERT(pv.getSize() == R);
}
