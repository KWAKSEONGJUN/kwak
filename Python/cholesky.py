# 입력: 양의 정부호 대칭행렬 A, 열벡터 b
# 출력: 해 x

import numpy as np
import sys

def choleskyLU(A, b):
    n = len(b);
    L = np.zeros((n,n))

    #하삼각 행렬
    for i in range(0, n):
        for j in range(0, i):
            L[i, j] = (A[i, j] - np.dot(L[i, 0:j], L[j, 0:j])) / L[j, j]
        L[i, i] = np.sqrt(A[i,i] - np.dot(L[i, 0:i], L[i, 0:i]))

        
    # 이 부분은 확인 부분이므로 생략 가능
    print(L)

    #대입법
    z = np.zeros([n, 1])
    z[0] = b[0] / L[0,0]
    for i in range(1, n):
        z[i] = (b[i] - np.dot(L[i, 0:i], z[0:i])) / L[i,i]

    #역대입법
    U = np.transpose(L)
    x = np.zeros((n, 1))
    x[n-1] = z[n-1] / U[n-1, n-1]
    for i in range(n-2, -1, -1):
        x[i] = (z[i] - np.dot(U[i, i+1:n], x[i+1:n])) / U[i,i]
                        #내적

    return x

# A = np.array([[16.0, -12.0, -12.0, -16], [-12.0, 25.0, 1.0, -4.0], [-12.0, 1.0, 17.0, 14.0], [-16.0, -4.0, 14.0, 57.0]])
# b = np.array([[2.0], [3.0], [4.0], [5.0]])
