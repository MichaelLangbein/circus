import numpy as np
from infix import or_infix

@or_infix
def fan(vecA, vecB):
    

@or_infix
def mxv (matrix, vec):
    return matrix.dot(vec)
    


class NN:

    def __init__(self, layerSizes):
        self.L = len(layerSizes)
        self.x = []
        self.W = []
        self.y = []
        self.dEdx = []
        self.dEdW = []
        for l in range(1, self.L):
            f = layerSizes[l-1]
            t = layerSizes[l]
            self.W[l] = np.zeros((f,t))



    def actFct(self, x):
        return 1. / (1. + np.exp(x))


    def diffAct(self, x):
        return np.exp(x) / (1. + np.exp(x))**2


    def predict(self, inpt):
        # 1.1.  First Layer
        self.y[0] = inpt
        # 1.2.  Higher layers
        for l in range(1, self.L):
            self.x[l] = self.W[l] |mxv| self.y[l-1]
            self.y[l] = self.actFct(self.x[l])
        
        return self.y[self.L]


    def backprop(self, target):
        # 2.1.  Top Layer
        self.dEdx[L] = (target - self.y[L]) * self.diffAct(self.x[L])
        self.dEdW[L] = self.dEdx[L] |fan| self.y[L-1]

        # 2.2.  Lower layers
        for l in range(self.L-1, 1):
            self.dEdx[l] = self.dEdx[l+1] * self.W[l+1] * self.diffAct(self.x[l])
            self.dEdW[l] = self.dEdx[l] |fan| self.y[l-1]
        
        return self.dEdW

        
        def training(self, inputs, targets):

            alpha = 1

            for s in range(len(inputs)):

                inpt = inputs[s]
                target = targets[s]

                output = self.predict(inpt)
                dEdW = self.backprop(target)

                for l in range(self.L):
                    self.W[l] -= alpha * dEdW[l]
                
                alpha *= 0.95