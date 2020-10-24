# 입력: 정칙행렬 A, 열벡터 b
# 출력: 해 x

import numpy as np
import sys

def gaussElimin(A, b):
    n = len(b);
    #상삼각 행렬(사다리꼴 행렬)
    for j in range(0, n-1):
        #부분 피봇
        max = np.abs(A[j,j])
        for k in range(j+1, n):
            temp = np.abs(A[k,j])
            if max < temp:
                max = temp
                l = k
        if max != np.abs(A[j,j]):
            temp = np.copy(A[j, :]); tempb = np.copy(b[j])
            A[j, :] = np.copy(A[l, :]); b[j] = np.copy(b[l])
            A[l, :] = temp; b[l] = tempb
        print(A); print(b)

        # 피봇이 0인지 체크
        if np.abs(A[j, j] - 0.0) < sys.float_info.epsilon:
            for k in range(j+1, n):
                if np.abs(A[k,j] - 0.0) > sys.float_info.epsilon:
                    temp = np.copy(A[k, :]); tempb = np.copy(b[k])
                    A[k, :] = A[j, :]; b[k] = b[j]
                    A[j, :] = temp; b[j] = tempb
                    break

        for i in range(j+1, n):
            lam = A[i,j] / A[j,j]
            # A[i, j+1 : n] = A[i, j+1 : n] - lam * A[j, j+1 :n]
            A[i,:] = A[i,:] - lam * A[j, :]
            b[i] = b[i] - lam * b[j]

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
        x[i] = (b[i] - np.dot(A[i, i+1:n], x[i+1:n])) / A[i,i]
                        #내적

    return x


A = np.array([[1.0, -3.0, 3.0], [-3.0, 2.0, 3.0], [-1.0, 2.0, -1.0]])
b = np.array([[-6.0], [-13.0], [3.0]])

x = gaussElimin(A, b)

print(x)
