import numpy as np
import matplotlib.pyplot as plt



def conv (M, K):
    R, C = M.shape
    D, U = K.shape
    M2 = np.zeros(M.shape)
    for r in range(R):
        for c in range(C):
            con = 0
            for d in range(D):
                for u in range(U):
                    ir = (r+d)%R
                    ic = (c+u)%C
                    con += M[ir, ic] * K[d,u]
            M2[r,c] = con
    return M2


M = np.array([[2,1],[1,0]])
K = np.array([[1,1],[1,0]])
M2 = conv(K, M)
print M2