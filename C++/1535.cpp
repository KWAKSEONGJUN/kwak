#include <iostream>
using namespace std;

pair<int, int> a[21];
int N, mx=0;

void f(int pos, int life, int happy)
{
    if(pos == N)
    {
        if(life > 0)
        {
            mx = max(mx, happy);
        }
        return;
    }

    f(pos+1, life-a[pos].first, happy+a[pos].second);
    f(pos+1, life, happy);


}

int main()
{
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &a[i].first);
    }
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a[i].second);
    }

    f(0, 100, 0);

    printf("%d\n", mx);

    return 0;
}