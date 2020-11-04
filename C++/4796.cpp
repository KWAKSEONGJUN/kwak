#include <iostream>

using namespace std;

int main()
{
    int L, P, V, n = 1;
    int pnum, rnum, res;

    while(true)
    {
        scanf("%d %d %d", &L, &P, &V);
        if(L == 0)
            return 0;
        else
        {
            pnum = V / P;
            rnum = V % P;
            
            if(rnum > L) rnum = L;
            res = L * pnum + rnum;
        }
        printf("Case %d: %d\n", n, res);
        n++;
    }

    return 0;
}