#include <bits/stdc++.h>

using namespace std;

int n, k, res = 0;
queue<int> q;
bool v[100001];

int main()
{
	scanf("%d %d", &n, &k);

	q.push(n);

	while(!q.empty())
	{
		int len = q.size();

		while(len--)
		{
			int tmp = q.front();
			q.pop();

			if(tmp == k)
			{
				printf("%d", res);
				return 0;
			}
			else if(!v[tmp])
			{
				v[tmp] = true;
				if(tmp+1 <= 100000)
					q.push(tmp+1);
				if(tmp-1>=0)
					q.push(tmp-1);
				if(tmp*2 <= 100000)
					q.push(tmp*2);
			}
		}
		res++;
	}

	return 0;
}