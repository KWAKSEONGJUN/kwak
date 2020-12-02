#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int r, c;
int sticker[11][11];
int laptop[41][41];

void rotate()
{
	int tmp[11][11];

	for(int i=0; i<c; i++)
	{
		for(int j=0; j<r; j++)
		{
			tmp[i][j] = sticker[r-j-1][i]; 
		}
	}
	swap(r,c);

	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			sticker[i][j] = tmp[i][j];
		}
	}
}


int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	for(int t = 0; t<k; t++)
	{
	
		scanf("%d %d", &r, &c);

		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				scanf("%d", &sticker[i][j]);
			
		int flag;

		for(int T=0; T<4; T++)
		{
			if(T != 0) rotate();
			flag = 0;

			for(int x=0; x<r; x++)
					{
						for(int y=0; y<c; y++)
						{
							//printf("%d ", sticker[x][y]);
						}
						//printf("\n");
					}
					//printf("\n");

			for(int i=0; i<n; i++)
			{
				flag = 0;
				for(int j=0; j<m; j++)
				{
					flag = 0;
					for(int x=0; x<r; x++)
					{
						for(int y=0; y<c; y++)
						{
							if(i+x >= n || j+y >= m || laptop[i+x][j+y] + sticker[x][y] > 1)
							{
								flag = 1;
								break;
							}
						}
						if(flag == 1)
							break;
					}
					if(flag != 1)
					{
						for(int x=0; x<r; x++)
						{
							for(int y=0; y<c; y++)
							{
								laptop[i+x][j+y] += sticker[x][y];
							}
						}
						break;
					}	
				}
				if(flag != 1) break;
			}
			if(flag != 1) break;
		}
	}

	int res = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(laptop[i][j] == 1) 
				{
					res++;
					//printf("1 ");
				}
			//else printf("0 ");
		}
		//printf("\n");
	}

	printf("%d", res);

	return 0;
}