from nn import NN


class SampleLoader:
    def __init__(self, pathToFile):
        self.file = open(pathToFile, "r")
    
    def getNextSample(self):
        line = self.file.readline()
        if not line:
            return False
        inpt = line.split("   ")
        inpt = [x for x in inpt if x is not ""]
        inpt = [float(x) for x in inpt]
        outpt = inpt.pop()
        return (inpt, outpt)


sl = SampleLoader("/home/michael/Desktop/c_workspace/nn/data/mnist/mnist_train_short.amat")
inpts = []
outpts = []
for i in range(100):
    inpt, outpt = sl.getNextSample()
    inpts.append(inpt)
    outpts.append(outpt)


nn = NN([784, 1000, 1000, 500, 100, 10])
steps = 1000
alpha0 = 0.1
nn.training(inpts, outpts, steps, alpha0)