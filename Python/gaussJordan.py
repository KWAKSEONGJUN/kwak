# 입력: 정칙행렬 A, 열벡터 b
# 출력: 해 x

import numpy as np
import sys

def gaussJordan(A):
    n = len(A);
    E = np.array([[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]])
    #상삼각 행렬(사다리꼴 행렬)
    for j in range(0, n-1):
        #부분 피봇
        if j == 0:
            max = np.abs(A[j,j])
            for k in range(j+1, n):
                temp = np.abs(A[k,j])
                if max < temp:
                    max = temp
                    l = k
            if max != np.abs(A[j,j]):
                temp = np.copy(A[j, :]); tempE = np.copy(E[j, :])
                A[j, :] = np.copy(A[l, :]); E[j] = np.copy(E[l, :])
                A[l, :] = temp; E[l, :] = tempE

        # 피봇이 0인지 체크
        if np.abs(A[j, j] - 0.0) < sys.float_info.epsilon:
            for k in range(j+1, n):
                if np.abs(A[k,j] - 0.0) > sys.float_info.epsilon:
                    temp = np.copy(A[k, :]); tempE = np.copy(E[k, :])
                    A[k, :] = A[j, :]; E[k] = E[j, :]
                    A[j, :] = temp; E[j, :] = tempE
                    break

        for i in range(j+1, n):
            lam = A[i,j] / A[j,j]
            A[i,:] = A[i,:] - lam * A[j, :]
            E[i, :] = E[i, :] - lam * E[j, :]

    # 해의 존재 유무 확인
    if (np.prod(np.diag(np.abs(A))) - 0.0) < sys.float_info.epsilon:
        print('해가 존재하지 않거나 무수히 많음')
        exit()

    for j in range(n-1, 0, -1):
        for i in range(j-1, -1, -1):
            lam = A[i,j] / A[j,j]
            A[i,:] = A[i,:] - lam * A[j, :]
            E[i, :] = E[i, :] - lam * E[j, :]
    
    for j in range(0, n):
        if(A[j, j] != 1):
            E[j, :] =  E[j, :] / A[j,j]
            A[j,j] /= A[j,j]
    
    R = np.zeros((n, 2*n))
    
    for j in range(0, n):
        R[:, j] = np.copy(A[:, j])
        
    for j in range(n, 2*n):
        R[:, j] = np.copy(E[:, j-n])

    print(R);

    return E
