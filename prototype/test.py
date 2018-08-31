import numpy as np
import matplotlib.pyplot as plt


def outer(vecA, vecB):
    return np.outer(vecA, vecB)
    

def inner(matrix, vec):
    return matrix.dot(vec)
    


class NN:

    def __init__(self, layerSizes):
        nrLayers = len(layerSizes) - 1
        self.L = nrLayers - 1 # we count from 0
        self.x = [0] * nrLayers
        self.W = [0] * nrLayers
        self.b = [0] * nrLayers
        self.y = [0] * nrLayers
        self.dEdx = [0] * nrLayers
        self.dEdW = [0] * nrLayers
        self.dEdb = [0] * nrLayers
        for l in range(0, self.L+1): # range is exclusive last value
            f = layerSizes[l]
            t = layerSizes[l+1]
            self.W[l] = np.random.rand(t, f) - 0.5
            self.b[l] = np.random.rand(t) - 0.5
        if layerSizes == [2,2,1]:
            self.W[0] = np.array([ [1.0, 1.0], [-1.0, -1.0] ])
            self.b[0] = np.array([0.5, -1.5] )
            self.W[1] = np.array([ [1.0, 1.0] ])
            self.b[1] = np.array([1.5])



    def actFct(self, x):
        return 1. / (1. + np.exp(x))


    def diffAct(self, x):
        return np.exp(-x) / (1. + np.exp(-x))**2


    def predict(self, inpt):
        # 1.1.  First Layer
        self.x[0] = inner( self.W[0], inpt ) + self.b[0]
        self.y[0] = self.actFct(self.x[0])

        # 1.2.  Higher layers
        for l in range(1, self.L+1): # range is exclusive last value
            self.x[l] = inner( self.W[l], self.y[l-1] ) + self.b[l]
            self.y[l] = self.actFct(self.x[l])
        
        return self.y[self.L]


    def backprop(self, inpt, target):

        # 2.1.  Top Layer
        self.dEdx[self.L] = (self.y[self.L] - target) * self.diffAct(self.x[self.L])
        self.dEdW[self.L] = outer( self.dEdx[self.L], self.y[self.L-1] )
        self.dEdb[self.L] = self.dEdx[self.L]

        # 2.2.  Lower layers
        for l in range(self.L-1, 0, -1): # range is exclusive last value
            self.dEdx[l] = inner( np.transpose(self.W[l+1]), self.dEdx[l+1] ) * self.diffAct(self.x[l])
            self.dEdW[l] = outer( self.dEdx[l], self.y[l-1] )
            self.dEdb[l] = self.dEdx[l]

        # 2.3 First layer
        self.dEdx[0] = inner( np.transpose(self.W[1]), self.dEdx[1] ) * self.diffAct(self.x[0])
        self.dEdW[0] = outer( self.dEdx[0], inpt )
        self.dEdb[0] = self.dEdx[0]

        return (self.dEdW, self.dEdb)

        
    def training(self, inputs, targets, repetitions, alpha, decay):

        offBy = []
        alphas = []

        for r in range(repetitions):
            print "now working on {}th epoch with alpha = {}".format(r, alpha)
            dEdW_total = [0] * (self.L + 1)
            dEdb_total = [0] * (self.L + 1)

            for s in range(len(inputs)):
                print "now training on {}th sample".format(s)

                inpt = inputs[s]
                target = targets[s]

                output = self.predict(inpt)
                dEdW, dEdb = self.backprop(inpt, target)
                for l in range(len(dEdW)):
                    dEdW_total[l] += dEdW[l]
                    dEdb_total[l] += dEdb[l]

                print "Training result: should be {}, is {}".format(target, output)
                offBy.append(abs(target - output))
                alphas.append(alpha)

            for l in range(self.L + 1): # range is eclusive last value
                self.W[l] -= alpha * dEdW_total[l]
                self.b[l] -= alpha * dEdb_total[l]
                #print dEdW_total[l]
            
            alpha = decay(alpha)
        

        plt.plot(offBy)
        plt.plot(alphas)
        plt.show()





inputs = []
targets = []
for a in [0,1]:
    for b in [0,1]:
        o = [(a+b)%2]
        inputs.append([a, b])
        targets.append(o)




nn = NN([2, 2, 1])
steps = 2
alpha0 = 0.1
#nn.training(inputs, targets, steps,  alpha0, lambda a: a - alpha0/steps)
print nn.predict([0,0])
print nn.predict([1,0])
print nn.predict([0,1])
print nn.predict([1,1])
