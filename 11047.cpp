#include <iostream>
using namespace std;

int main()
{
    int N, K, res = 0;;
    int coin[10];

    scanf("%d %d", &N, &K);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &coin[i]);
    }

    for(int i=N-1; i>=0; i--)
    {
        if(coin[i] <= K)
        {
            res += K / coin[i];
            K %= coin[i];
        }
    }

    printf("%d\n", res);
    return 0;
}