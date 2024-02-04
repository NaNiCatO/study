import numpy as np

def mat_randint(s):
    return np.random.randint(low=0,high=10,size=(s,s))

def row_swap(A, i, j):
    A[[i, j], :] = A[[j, i], :]
    return A

def mat_elim(A):
    A = A.astype(float)
    n = A.shape[0]
    E = np.identity(n)

    for j in range(n):
        for i in range(j+1,n):
            if A[j,j] == 0:
                row_swap(A, j, i)
                row_swap(E, j, i)
            factor = -A[i, j] / A[j, j]
            e_mat = np.identity(n)
            e_mat[i, j] = factor
            for col in range(n):
                A[i][col] += factor * A[j][col]
            E = e_mat@E
    return E


A = mat_randint(3)
print("\nA = \n",A)

E = mat_elim(A)
print("\nE = \n",E)
print("\nEA = \n",np.round(E@A,3))