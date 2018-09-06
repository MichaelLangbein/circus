import numpy as np
import matplotlib.pyplot as plt


# As simplified as it gets
# - 1d convolution only 
# - 1 kernel per convoltion layer
# - mean pooling only
# - stochastic training only


def convol(y, w):
    z = np.zeros(shape=y.shape)
    for n in range(len(y)):
        z[n] = y[n-1]*w[0] + y[n]*w[1] + y[n+1]*w[2]
    return z


def diffyConvol(y, w):
    (R,_) = y.shape
    z = np.zeros(shape=(R,R))
    for r in range(R):
        for c in range(R):
            if c - r == -1: 
                z[r,c] = w[0]
            elif c - r == 1:
                z[r,c] = w[2]
            elif c - r == 0:
                z[r,c] = w[1]
    return z


def diffwConvol(y, w):
    (R,_) = y.shape
    z = np.zeros(shape=(R,3))
    for r in R:
        z[r, 0] = y[r-1]
        z[r, 1] = y[r]
        z[r, 2] = y[r+1]
    return z


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
        self.y_lmin1 = y_lmin1
        self.x_l = self.W * y_lmin1 + self.b
        y_l = self.activation(self.x_l)
        return y_l

    def backprop(self, delta_l, alpha):
        dEdX_l = delta_l * self.derivActivation(self.x_l)
        dEdW_l = dEdX_l.T * self.y_lmin1.T
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
        self.y_lmin1 = y_lmin1
        self.x_l = convol(y_lmin1, self.w)
        y_l = self.activation(self.x_l)
        return y_l

    def backprop(self, delta_l, alpha):
        dEdX_l = delta_l * self.derivActivation(self.x_l)
        dEdw_l = dEdX_l.T * diffyConvol(self.y_lmin1, self.w)
        delta_lmin1 = dEdX_l * diffwConvol(self.y_lmin1, self.w)

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
        (R, _) = y_lmin1.shape
        R2 = R / float(self.r)
        y_l = np.zeros(shape=(R2, 1))
        for r in range(R2):
            r1 = r*self.r
            r2 = (r+1)*self.r
            y_l[r] = np.mean(y_lmin1[r1:r2])
        return y_l


    def backprop(self, delta_l, alpha):
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
        # Forward pass
        outpt = self.predict(inpt)
        # Backward pass
        delta = (target - outpt).T
        for l in range(len(self.layers), -1, -1):
            delta = self.layers[l].backprop( delta, alpha )

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

    nn.predict(np.random.rand(1250))
