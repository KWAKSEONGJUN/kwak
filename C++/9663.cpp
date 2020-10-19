#include <iostream>

using namespace std;

int N;
int a[15];
int cnt = 0;
int vi[15];
int vj[15];

void f(int ni, int nj)
{
    for(int i=0; i<nj; i++)
    {
        if(ni == vi[i]) return;
        if(nj == vj[i]) return;
        if(abs(ni- vi[i]) == abs(nj-vj[i])) return;
    }

    if(nj == (N-1))
    {
        cnt++;
        return;
    }

    vi[nj] = ni;
    vj[nj] = nj;

    for(int i=0; i<N; i++)
    {
        f(i, nj+1);
    }
}

int main()
{
    scanf("%d", &N);

    for(int i=0; i<N; i++)
        f(i, 0);
    printf("%d\n", cnt);
    return 0;
}