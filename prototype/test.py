import numpy as np


def outer(vecA, vecB):
    return np.outer(vecA, vecB)
    

def inner(matrix, vec):
    return matrix.dot(vec)
    


class NN:

    def __init__(self, layerSizes):
        self.L = len(layerSizes)
        self.x = [0] * self.L
        self.W = [0] * self.L
        self.y = [0] * self.L
        self.dEdx = [0] * self.L
        self.dEdW = [0] * self.L
        for l in range(1, self.L):
            f = layerSizes[l-1]
            t = layerSizes[l]
            self.W[l] =  np.random.rand(f,t)



    def actFct(self, x):
        return 1. / (1. + np.exp(x))


    def diffAct(self, x):
        return np.exp(x) / (1. + np.exp(x))**2


    def predict(self, inpt):
        # 1.1.  First Layer
        self.y[0] = inpt
        # 1.2.  Higher layers
        for l in range(1, self.L):
            self.x[l] = inner( self.W[l], self.y[l-1] )
            self.y[l] = self.actFct(self.x[l])
        
        return self.y[self.L]


    def backprop(self, target):
        # 2.1.  Top Layer
        self.dEdx[L] = (target - self.y[L]) * self.diffAct(self.x[L])
        self.dEdW[L] = outer( self.dEdx[L], self.y[L-1])

        # 2.2.  Lower layers
        for l in range(self.L-1, 1):
            self.dEdx[l] = self.dEdx[l+1] * self.W[l+1] * self.diffAct(self.x[l])
            self.dEdW[l] = outer( self.dEdx[l], self.y[l-1] )
        
        return self.dEdW

        
    def training(self, inputs, targets):

        alpha = 1

        for s in range(len(inputs)):
            print "now training on {}th sample with alpha = {}".format(s, alpha)

            inpt = inputs[s]
            target = targets[s]

            output = self.predict(inpt)
            dEdW = self.backprop(target)

            for l in range(self.L):
                self.W[l] -= alpha * dEdW[l]
            
            alpha *= 0.95




inputs = []
targets = []
for i in range(30):
    a = np.random.randint(2)
    b = np.random.randint(2)
    o = (a+b)%2
    inputs.append([a, b])
    targets.append(o)

nn = NN([2, 3, 4, 3, 1])
nn.training(inputs, targets)
print nn.predict([1,0])