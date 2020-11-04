#include <iostream>
#include <algorithm>

using namespace std;

int a[11];

int main()
{
    int D, V, time = 0;
    int Dsum=0, Vsum=0;
    for(int i=0; i<11; i++)
    {
        scanf("%d %d", &a[i], &V);
        Vsum += V*20;
    }

    sort(a, a+11);

    for(int i=0; i<11; i++)
    {
        Dsum = Dsum + time + a[i];
        time += a[i];
    }

    printf("%d\n", Dsum + Vsum);
    return 0;
}