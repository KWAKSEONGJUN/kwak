#include <iostream>
using namespace std;

int a[10001];

void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i] < a[j]) swap(&a[i], &a[j]);
        }
    }
    
    for(int i=0; i<n; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}