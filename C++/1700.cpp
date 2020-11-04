#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int N, K;
    int a[101];
    int w[101];
    int tap[101];
    int mn = 101;
    int flag=0;
    int pos;
    int cnt = 0;

    memset(w, 0 ,sizeof(w));
    scanf("%d %d", &N, &K);
    for(int i=0; i<K; i++)
    {
        scanf("%d", &a[i]);
    }    

    for(int i=0; i<K; i++)
    {
        w[a[i]]++;       
    }
    int index, s;
    for(int i=0; i<K; i++)
    {
        flag = 0;
        if(i == 0) 
        {
            tap[i] = a[i];
            index = 1;
        }
        else
        {
            for(int j=0; j<index; j++)
            {
                if(a[i] == tap[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                tap[index] = a[i];
                index++;
            }
                
            if(index >= N) 
            {
                s = i+1;
                break;
            }
        }
    }
   
    for(int i=s; i<K; i++)
    {
        flag = 0;
        for(int j=0; j<i; j++)
        {
            if(a[i] == tap[j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            pos = 0;
            for(int j=0; j<N; j++)
            {
                mn = min(mn, w[tap[j]]);
                if(mn == w[tap[j]])
                {
                    pos = j;
                }
            }
            
            tap[pos] = a[i];
            
            cnt++;
        }

        memset(w, 0, sizeof(w));
         for(int k=i+1; k<K; k++)
            {
                w[a[k]]++;       
            }
            
            for(int k=0; k<N; k++)
            {
                printf("-%d", tap[k]);
            }
            printf("\n");
        
    }

    printf("%d\n", cnt);

    return 0;
}