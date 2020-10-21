#include <iostream>
using namespace  std;

int* solution(int v[][2])
{
    int *result = (int*)malloc(sizeof(int)*2);

    result[0] = v[0][0] ^ v[1][0] ^ v[2][0];
    result[1] = v[0][1] ^ v[1][1] ^ v[2][1];
    return result;
}

int main()
{
    int v[3][2];
    int *result;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        scanf("%d", &v[i][j]);
    }

    result = solution(v);

    printf("%d %d\n", result[0], result[1]);

    return 0;
}