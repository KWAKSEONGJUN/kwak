from math import factorial

def taylor(x, n):
    sum = 0;
    for i in range(0,n+1):
        sum += 1*(x)**i / factorial(i)

    print(sum)

    

