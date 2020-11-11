#입력: 행렬 A, 초기벡터 x, 이동변수 alpha, 최대 반복횟수 kmax
#출력: 우세 고유값, 우세 고유벡터

import numpy as np

def invpower(A, x, kmax, alpha):
    m, n = A.shape
    if(m != n):
        print('정방행렬이 아님')
        return;
    
    B = A - np.eye(n)*alpha
    for k in range(0, kmax):
        y = np.linalg.solve(B, x) # B*y = x => y의 해
     
        # 1차 방법
        # index = np.argmax(np.abs(y)) #절대값이 최대값인 인덱스
        # value = y[index]
        # vector = y / value
        # 2차 방법
        value = np.dot(x, y)
        vector = y / np.linalg.norm(y)
        value = (1.0/value) + alpha
        print('k={0} \t 고유값={1} \t 고유벡터={2}'.format(k, value, vector))
        x = np.copy(vector)
    
    return value, vector

A = np.array([[2.0, -1.0, 1.0], [-1.0, 1.0, -2.0], [1.0, -2.0, 1.0]])
x = np.array([1.0, 1.0, 1.0])
kmax = 100
alpha = 2
a, b = invpower(A, x, kmax, alpha)

print(a); print(b);

w, V = np.linalg.eig(A)
print(w); print(V);