import numpy as np
import matplotlib.pyplot as plt


class Layer:
    def prop(self, x):
        raise Exception("prop wurde nicht implementiert!")

    def backprop(self, delta_l, x_l, y_lmin1, alpha):
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

    def backprop(self, delta_l, x_l, y_lmin1, alpha):
        dEdX_l = delta_l * derivActivation(x_l)
        dEdW_l = dEdX_l.T * y_lmin1.T
        dEdb_l = dEdX_l
        delta_lmin1 = dEdX_l self.W

        self.W -= alpha*dEdW_l
        self.b -= alpha*dEdb_l
        
        return delta_lmin1

    def activation(self, z):
        return 1.0 / (1.0 + np.exp(-z))

    def derivActivation(self, z):
        return np.exp(-z) / (1.0 + np.exp(-z))**2
    
    

class ConvolutionLayer(Layer):

    def __init__(self, K):
        self.K = K

    def prop(self, M):
        return crossCorr(self.K, M)


    def backprop(self, delta_l, x_l, y_lmin1, alpha):
        pass



class MaxPoolingLayer(Layer):

    def __init__(self, r):
        self.r = r


    def prop(self, M):
        pass

    def backprop(self, delta_l, x_l, y_lmin1, alpha):
        pass



class VectorizeLayer(Layer):
    
    def prop(self, M):
        return np.reshape(M)

    def backprop(self, delta_l, x_l, y_lmin1, alpha):
        return delta_l



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
        x = []
        y = []

        # Forward pass
        x[0] = inpt
        for l in range(L):
            y[l] = layers[l].prop(x[l])
            x[l+1] = y[l]

        # Backward pass
        delta[L] = (outpt - target).T
        for l in range(L, -1, -1):
            delta[l-1] = layers[l].backprop( delta[l], x[l], y[l-1], alpha )



    def train(self, inpts, outpts):
        T = len(inpts)
        alpha = 1
        for t in range(T):
            self.singleTrainingStep(inpts[t], outpts[t], alpha)
            alpha -= 1. / T





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
