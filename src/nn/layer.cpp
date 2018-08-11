#include <math.h> 
#include "layer.hpp"


Layer::Layer(int size) : size(size) {
	
}

void Layer::evaluate(double* dataIn, double* dataOut) {
	for(int i = 0; i < size; i++) {
		dataOut[i] = 1.0 / (1.0 + exp(dataIn[i]));
	}	
}