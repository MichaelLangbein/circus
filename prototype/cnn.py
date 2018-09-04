import numpy as np
import matplotlib.pyplot as plt


class Layer:
    def prop(self, x):
        raise Exception("prop wurde nicht implementiert!")

    def backprop(self, dEdX):
        raise Exception("backprop wurde nicht implementiert!")

    def dream(self, dEdW):
        raise Exception("dream wurde nicht implementiert!")



class FullyConnectedLayer(Layer):

    def __init__(self, W, b):
        self.W = W
        self.b = b

    def prop(self, x):
        z = self.W * x + self.b
        a = self.activation(z)
        return a

    def backprop(self, dEdX):
        dEdW = None
        dEdb = None
        dEdx = None
        return (dEdW, dEdb, dEdX)

    def activation(self, z):
        return 1.0 / (1.0 + np.exp(-z))


    def derivActivation(self, z):
        return np.exp(-z) / (1.0 + np.exp(-z))**2
    
    

class ConvolutionLayer(Layer):

    def __init__(self, K):
        self.K = K

    def prop(self, M):
        return crossCorr(self.K, M)


    def backprop(self, dEdX):
        pass



class MaxPoolingLayer(Layer):

    def __init__(self, r):
        self.r = r


    def prop(self, M):
        pass

    def backprop(self, dEdX):
        pass



class VectorizeLayer(Layer):
    
    def prop(self, M):
        return np.reshape(M)

    def backprop(self, dEdX):
        return dEdX



class Network:

    def __init__(self, layers):
        self.layers = layers

    def predict(self, X):
        inpt = X
        for layer in self.layers:
            outpt = layer.prop(inpt)
            inpt = outpt
        return outpt

    def train(self, inpts, outpts):
        pass






if __name__ == "__main__":
    nn = Network([
            ConvolutionLayer(np.random.rand(5,5)),
            MaxPoolingLayer(5),
            ConvolutionLayer(np.random.rand(5,5)),
            MaxPoolingLayer(5),
            VectorizeLayer(),
            FullyConnectedLayer(np.random.rand(30, 50), np.random.rand(30, 1)),
            FullyConnectedLayer(np.random.rand(1, 30), np.random.rand(1, 1))
        ])

    nn.predict(M)
