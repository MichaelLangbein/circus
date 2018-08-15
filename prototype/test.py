import numpy as np


class Layer:
    def __init__(self, count):
        self.count = count

    def predict(self, inpt):
        return 1. / (1. + np.exp(-inpt))

    def d_activ_dw(self, inpt):
        return np.exp(-inpt) / (1. + np.exp(-inpt))**2 


class Connection:
    def __init__(self, r, c):
        self.conn = np.random.rand(r,c)

    def propagate(self, inpt):
        return self.conn.dot(inpt)


class NN:
    def __init__(self, sizes):
        self.conns = []
        self.phis = []
        self.layers = []
        self.acts = []
        for l in range(1, len(sizes)):
            lastSize = sizes[l-1]
            currSize = sizes[l]
            self.conns.append(Connection(currSize, lastSize))
            self.layers.append(Layer(currSize))

    def evaluate(self, inpt):
        for l in range(len(self.layers)):
            conn = self.conns[l]
            layer = self.layers[l]
            phi = conn.propagate(inpt)
            act = layer.predict(phi)
            inpt = act
        return act

    def backprop(self, inpt, outpt):

        # Forward pass
        for l in range(len(self.layers)):
            conn = self.conns[l]
            layer = self.layers[l]
            self.phis[l] = conn.propagate(inpt)
            self.acts[l] = layer.predict(self.phis[l])
            inpt = self.acts[l]

        # Backward pass
        for l in range(len(self.layers), 1):
            dadp = self.layers[l].d_activ_dw(self.phis[l])
            aLmin1 = self.acts[l-1]
            dEdW = dadp * aLmin1
            self.conns[l].conn += dEdW


if __name__ == "__main__":
    nn = NN([3,5,4])
    inpt = [1.1, 3.2, 0.8]
    outpt = nn.evaluate(inpt)
    print(outpt) 
            
            
            
