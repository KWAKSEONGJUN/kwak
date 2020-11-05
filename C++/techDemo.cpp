#include <iostream>
#include <vector>
using namespace std;

int main() {
 
    int a[3][2];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    int res[2];
    res[0] = a[0][0] ^ a[1][0] ^ a[2][0];
    res[1] = a[0][1] ^ a[1][1] ^ a[2][1];
    

    printf("%d %d", res[0], res[1]);

    return 0;
}