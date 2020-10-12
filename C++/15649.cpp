#include <iostream>
using namespace std;

int n, m;
int result[9];
bool visit[9];

void f(int pos)
{
    if(pos == m)
    {
        for(int i=0; i<m; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(visit[i] == false)
        {
            result[pos] = i;
            visit[i] = true;
            f(pos+1);
            visit[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    f(0);

    return 0;
}