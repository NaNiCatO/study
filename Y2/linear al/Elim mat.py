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

                selected_row = None
                for k in range(j+1,n):
                    if A[k,j] != 0:
                        selected_row = k
                        break

                if selected_row == None:
                    return None
                
                A = row_swap(A, j, selected_row)
                E = row_swap(E, j, selected_row)
            multiplier = -A[i, j] / A[j, j]
            E_mat = np.identity(n)
            E_mat[i, j] = multiplier
            for col in range(n):
                A[i][col] += multiplier * A[j][col]
            E = E_mat@E
    return E




A = mat_randint(3)
A =  np.array([[3, 1, 8],
 [6, 4, 7],
 [1, 2, 7]])
print("\nA = \n",A)

E = mat_elim(A)
print("\nE = \n",E)
print("\nEA = \n",np.round(E@A,3))