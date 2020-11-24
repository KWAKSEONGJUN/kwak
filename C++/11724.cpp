#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> v;
bool check[1001];
int res = 0;

void f(int a, int b)
{
	if(!check[a])
	{	
		check[a] = true;
		
		int len = v[a].size();
		for(int i=0; i<len; i++)
		{

			f(v[a][i], i);
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);

	v.resize(n+1);
	v[0].push_back(0);
	for(int i=0; i<m; i++)
	{
		pair<int, int> tmp;
		scanf("%d %d", &tmp.first, &tmp.second);

		v[tmp.first].push_back(tmp.second);
		v[tmp.second].push_back(tmp.first);
	}

	for(int i=1; i<=n; i++)
	{
		if(!check[i])
		{
			f(i, 0);
			res++;
		}
	}

	printf("%d", res);

	return 0;
}