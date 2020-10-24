# 입력: 삼중대각 정칙행렬 A, 열벡터 b
# 출력: 해 x

import numpy as np
import sys

def triDiagonal(A, b):
    n = len(b)
    #상삼각 행렬(사다리꼴 행렬)
    for j in range(0, n-1):
        lam = A[j+1, j] / A[j, j]
        A[j+1, j] = 0.0
        A[j+1, j+1] = A[j+1, j+1] - lam * A[j, j+1]
        b[j+1] = b[j+1] - lam * b[j]
        # for i in range(j+1, n):
        #     lam = A[i,j] / A[j,j]
        #     # A[i, j+1 : n] = A[i, j+1 : n] - lam * A[j, j+1 :n]
        #     A[i,:] = A[i,:] - lam * A[j, :]
        #     b[i] = b[i] - lam * b[j]

    # 이 부분은 확인 부분이므로 생략 가능
    print(A)
    print(b)

    # 해의 존재 유무 확인
    if (np.prod(np.diag(np.abs(A))) - 0.0) < sys.float_info.epsilon:
        print('해가 존재하지 않거나 무수히 많음')
        exit()

    #역대입법
    x = np.zeros((n, 1))
    x[n-1] = b[n-1] / A[n-1, n-1]
    for i in range(n-2, -1, -1):
        x[i] = (b[i] - (A[i, i+1] * x[i+1])) / A[i, i]
                        #내적

                        

    return x

A = np.array([[2.0, 6.0, 0.0], [-2.0, -7.0, -3.0], [0.0, 2.0, -4.0]])
b = np.array([[-10.0], [3.0], [-16.0]])

x = triDiagonal(A, b)
print(x)



