#include <iostream>
#include <algorithm>

using namespace std;

int main()
{	
	int N, L, pos, res = 0;
	int a[1001];
	scanf("%d %d", &N, &L);

	for(int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	sort(a, a+N);

	pos = 0;
	int point;

	
		for(int i=pos; i<N; i++)
		{
			if(i == pos)
				point = a[i];
			
			if(a[i] - point >= N)
			{
				res++;
				pos = i;
				break;
			}
			else if(a[i] - point < N && i == N - 1)
			{
				res++;
				pos = N;
				break;
			}
		}
	

	printf("%d\n", res);

	return 0;
}