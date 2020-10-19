#include <iostream>
using namespace std;


int N;
char arry[51][51];
int res = 1;
//int cas;

void f(int ni, int nj, char nc, int cas)
{
    if(ni < 0 || nj < 0 || ni >=N || nj >= N)
    {
        return;
    }

    int tmp = 1;

    //오른쪽
    if(cas == 1)
    {
        //행
        f(ni, nj+1, nc, 11);
        //열
        f(ni, nj+1, nc, 12);
        f(ni, nj, nc, 2);
        return;
    }
    else if(cas == 11)
    {
        for(int j=nj+1; j<N; j++)
        {
            if(arry[ni][j] == nc) tmp++;
            else break;
        }
        printf("###%c###\n", nc);
        printf("\n-%c %c-\n", arry[ni][nj+1], nc);
        printf("res: %d tmp: %d\n", res, tmp);
        res = max(res, tmp);
        
        return;
    }
    else if(cas == 12)
    {
        for(int i=ni+1; i<N; i++)
        {
            if(arry[i][nj] == nc) tmp++;
            else break; 
        }
        for(int i=ni-1; i>=0; i--)
        {
            if(arry[i][nj]== nc) tmp++;
            else break;
        }
printf("res: %d tmp: %d\n", res, tmp);
        res = max(res, tmp);

        return;
    }

     //왼쪽
    else if(cas == 2)
    {
        //행
        f(ni, nj-1, nc, 21);
        //열
        f(ni, nj-1, nc, 22);
        f(ni, nj, nc, 3);
        return;
    }
    else if(cas == 21)
    {
        for(int j=nj-1; j>=0; j--)
        {
            if(arry[ni][j] == nc) tmp++;
            else break;
        }
  printf("res: %d tmp: %d\n", res, tmp);
        res = max(res, tmp);
  
        return;
    }
    else if(cas == 22)
    {
        for(int i=ni+1; i<N; i++)
        {
            if(arry[i][nj] == nc) tmp++;
            else break; 
        }
        for(int i=ni-1; i>=0; i--)
        {
            if(arry[i][nj]== nc) tmp++;
            else break;
        }
printf("res: %d tmp: %d\n", res, tmp);
        res = max(res, tmp);

        return;
    }
    
        //위
    else if(cas == 3)
    {
        //행
        f(ni-1, nj, nc, 31);
        //열
        f(ni-1, nj, nc, 32);
        f(ni, nj, nc, 4);
        return;
    }
    else if(cas == 31)
    {
        for(int j=nj+1; j<N; j++)
        {
            if(arry[ni][j] == nc) tmp++;
            else break; 
        }

        for(int j=nj-1; j>=0; j--)
        {
            if(arry[ni][j] == nc) tmp++;
            else break;
        }
printf("res: %d tmp: %d\n", res, tmp);
        res = max(res, tmp);

        return;
    }
    else if(cas == 32)
    {
        for(int i=ni-1; i>=0; i--)
        {
            if(arry[i][nj]== nc) tmp++;
            else break;
        }
printf("res: %d tmp: %d\n", res, tmp);
        res = max(res, tmp);

        return;
    }

     
        //아래
    else if(cas == 4)
    {
        //행
        f(ni+1, nj, nc, 41);
        //열
        f(ni+1, nj, nc, 42);

        // if(nj+1 >= N)
        // {
        //    f(ni+1, 0, arry[ni+1][0], 1);
        // }
        // else
        // {
        //     f(ni, nj+1, arry[ni][nj+1], 1);
        // }
       
        return;
    }
    else if(cas == 41)
    {
        for(int j=nj+1; j<N; j++)
        {
            if(arry[ni][j] == nc) tmp++;
            else break; 
        }

        for(int j=nj-1; j>=0; j--)
        {
            if(arry[ni][j] == nc) tmp++;
            else break;
        }
        printf("res: %d tmp: %d\n", res, tmp);
        res = max(res, tmp);
        return;
    }
    else if(cas == 42)
    {
        for(int i=ni+1; i<N; i++)
        {
            if(arry[i][nj]== nc) tmp++;
            else break;
        }
        printf("res: %d tmp: %d\n", res, tmp);
        res = max(res, tmp);
        return;
    }
     
   
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%c", &arry[i][j]);

    f(0, 0, arry[0][0], 1);

    // for(int i=0; i<N; i++)
    // {
    //     for(int j=0; j<N; j++)
    //         f(i, j, arry[i][j], 1);
    // }
    f(3, 1, arry[3][2], 1);
    printf("%d\n", res);
    return 0;
}