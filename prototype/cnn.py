import numpy as np
import matplotlib.pyplot as plt


# As simplified as it gets
# - 1d convolution only 
# - 1 kernel per convoltion layer
# - mean pooling only
# - stochastic training only


def crossCorr(a, b):
    return a

def sigmoid(x):
    return 1.0 / (1.0 + np.exp(-x))

def dSigmoiddX(x):
    return np.exp(-x) / (1.0 + np.exp(-x))**2



class Layer:
    def prop(self, y_lmin1):
        raise Exception("prop wurde nicht implementiert!")

    def backprop(self, delta_l, x_l, y_lmin1, alpha):
        raise Exception("backprop wurde nicht implementiert!")

    def dream(self, dEdW):
        raise Exception("dream wurde nicht implementiert!")



class FullyConnectedLayer(Layer):

    def __init__(self, W, b):
        self.W = W
        self.b = b

    def prop(self, y_lmin1):
        x_l = self.W * y_lmin1 + self.b
        y_l = self.activation(x_l)
        return y_l

    def backprop(self, delta_l, x_l, y_lmin1, alpha):
        dEdX_l = delta_l * self.derivActivation(x_l)
        dEdW_l = dEdX_l.T * y_lmin1.T
        dEdb_l = dEdX_l
        delta_lmin1 = dEdX_l * self.W

        self.W -= alpha*dEdW_l
        self.b -= alpha*dEdb_l
        
        return delta_lmin1

    def activation(self, x):
        return sigmoid(x)

    def derivActivation(self, x):
        return dSigmoiddX(x)
    
    

class ConvolutionLayer(Layer):

    def __init__(self, w):
        self.w = w

    def prop(self, y_lmin1):
        x_l = crossCorr(y_lmin1, self.w)
        y_l = self.activation(x_l)
        return y_l

    def backprop(self, delta_l, x_l, y_lmin1, alpha):
        dEdX_l = delta_l * self.derivActivation(x_l)
        dEdw_l = crossCorr(dEdX_l.T , y_lmin1)
        delta_lmin1 = crossCorr(dEdX_l, self.w)

        self.w -= alpha*dEdw_l
        
        return delta_lmin1

    def activation(self, x):
        return sigmoid(x)

    def derivActivation(self, x):
        return dSigmoiddX(x)



class MeanPoolingLayer(Layer):

    def __init__(self, r):
        self.r = r

    def prop(self, y_lmin1):
        pass

    def backprop(self, delta_l, x_l, y_lmin1, alpha):
        dEdx = delta_l
        delta_lmin1 = dEdx / self.r
        return delta_lmin1





class Network:

    def __init__(self, layers):
        self.layers = layers

    def predict(self, X):
        inpt = X
        for layer in self.layers:
            outpt = layer.prop(inpt)
            inpt = outpt
        return outpt

    def singleTrainingStep(self, inpt, target, alpha):
        L = len(self.layers)
        delta = []
        y = []

        # Forward pass
        y[0] = inpt
        for l in range(1, L):
            y[l] = self.layers[l].prop(y[l-1])

        # Backward pass
        delta[L] = (y[L] - target).T
        for l in range(L, -1, -1):
            delta[l-1] = self.layers[l].backprop( delta[l], x[l], y[l-1], alpha )



    def train(self, inpts, outpts):
        T = len(inpts)
        alpha = 1
        for t in range(T):
            self.singleTrainingStep(inpts[t], outpts[t], alpha)
            alpha -= 1. / T





if __name__ == "__main__":
    nn = Network([
            ConvolutionLayer(np.random.rand(5,1)),
            MeanPoolingLayer(5),
            ConvolutionLayer(np.random.rand(5,1)),
            MeanPoolingLayer(5),
            FullyConnectedLayer(np.random.rand(30, 50), np.random.rand(30, 1)),
            FullyConnectedLayer(np.random.rand(1, 30), np.random.rand(1, 1))
        ])

    nn.predict(M)
