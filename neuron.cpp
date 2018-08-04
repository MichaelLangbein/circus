#include "neuron.hpp"


float Neuron::evaluate(float input) {
    return 1.0 / (1.0 + exp(-input));
}