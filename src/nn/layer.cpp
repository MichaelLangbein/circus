#include <math.h> 
#include "layer.hpp"


Layer::Layer(int size) : size(size) {
	
}

int Layer::getSize() {
	return size;
}

Vector Layer::evaluate(const Vector& dataIn) {
	if(dataIn.getSize() != size) throw "Layer requires input-vector of same size!";
	Vector dataOut(dataIn.getSize());
	for(int i = 0; i < size; i++) {
		dataOut[i] = 1.0 / (1.0 + exp(dataIn.get(i) ));
	}
	return dataOut;
}