#include <iostream>
using namespace std;

int N, K;
int up[9];
bool visit[9];
int order[9];
int weight = 500;
int res = 0;

void f(int pos)
{
    if(pos == N)
    {
        weight = 500;
        for(int i=0; i<N; i++)
        {
            if((weight + up[order[i]] - K) < 500) return;
            else
            {
                weight = weight + up[order[i]] - K;
            }
            
        }

        res++;
    }

    for(int i=0; i<N; i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            order[pos] = i;
            f(pos + 1);
            visit[i] = false;
        }
    }
}
int main()
{
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &up[i]);
    }

    f(0);
    printf("%d\n", res);
    return 0;
}