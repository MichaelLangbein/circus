#define BOOST_TEST_MODULE NeuronTest
#include "neuron.hpp"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( neuron_test ) {
    Neuron n;
    float result = n.evaluate(1);
    BOOST_CHECK(result - 0.731058598 < 0.001);
}
