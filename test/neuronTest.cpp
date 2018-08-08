#define BOOST_TEST_MODULE NeuronTest
#include "neuron.hpp"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( neuron_test ) {
    Neuron n();
    float result = n.evaluate(1.1);
    printf("result: %f \n", result);
    BOOST_CHECK_EQUAL(2+2, 4);
}