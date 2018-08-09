import numpy as np


class Layer:
    def __init__(self, count):
        self.count = count

    def predict(self, inpt):
        return 1. / (1. + np.exp(-inpt))        

class Connection:
    def __init__(self, r, c):
        self.conn = np.random.rand(r,c)

    def propagate(self, inpt):
        return self.conn.dot(inpt)

class NN:
    def __init__(self, sizes):
        self.layers = []
        self.conns = []
        for l in range(1, len(sizes)):
            lastSize = sizes[l-1]
            currSize = sizes[l]
            self.conns.append(Connection(currSize, lastSize))
            self.layers.append(Layer(currSize))

    def evaluate(self, inpt):
        for l in range(len(self.layers)):
            conn = self.conns[l]
            layer = self.layers[l]
            prp = conn.propagate(inpt)
            outpt = layer.predict(prp)
            inpt = outpt
        return outpt

    def optimize(self, testData):
        pass


if __name__ == "__main__":
    nn = NN([3,5,4])
    inpt = [1.1, 3.2, 0.8]
    outpt = nn.evaluate(inpt)
    print(outpt) 
            
            
            
