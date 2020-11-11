#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, mx=-1;
    int w[100001];
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &w[i]);   
    }

    sort(w, w + N);
    
    for(int i=0; i<N; i++)
    {
        mx = max(mx, w[i]*(N-i));
    }

    printf("%d\n", mx);
    
    return 0;
}