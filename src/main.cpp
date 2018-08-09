#include <stdio.h>
#include <string>
#include "neuron.hpp"



int main() {
  Neuron n;
  float result = n.evaluate(2);
  printf("result: %f \n", result);
  return 0;
}

