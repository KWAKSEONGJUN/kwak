#include <bits/stdc++.h>

using namespace std;


char maze[101][101];

int main()
{
	int n, m, cnt = 1;
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
	{
		scanf("%s", maze[i]);
	}

	pair<int, int> tmp = {0,0};
	queue<pair<int, int>> q;
	int v[101][101];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			v[i][j] = 0 ;
	}
		v[0][0] = 1;
	q.push(tmp);

	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			tmp = q.front();
			q.pop();
	
			if(tmp.first + 1 == n && tmp.second + 1 == m)
			{
				printf("%d", cnt);
				return 0;
			}
			//상
			if(tmp.first - 1 >= 0 && maze[tmp.first - 1][tmp.second] == '1' && !v[tmp.first-1][tmp.second])
			{
				tmp.first--;
				q.push(tmp);
				v[tmp.first][tmp.second] = 1;
				tmp.first++;
			}
			//하
			if(tmp.first + 1 < n && maze[tmp.first + 1][tmp.second] == '1' && !v[tmp.first + 1][tmp.second])
			{
				tmp.first++;
				q.push(tmp);
				v[tmp.first][tmp.second] = 1;
				tmp.first--;
			}
			//좌
			if(tmp.second - 1 >= 0 && maze[tmp.first][tmp.second - 1] == '1' && !v[tmp.first][tmp.second - 1])
			{
				tmp.second--;
				q.push(tmp);
				v[tmp.first][tmp.second] = 1;
				tmp.second++;
			}
			//우
			if(tmp.second + 1 < m && maze[tmp.first][tmp.second + 1] == '1' && !v[tmp.first][tmp.second+1])
			{
				tmp.second++;
				q.push(tmp);
				v[tmp.first][tmp.second] = 1;
				tmp.second--;
			}

		}
		cnt++;
	}
	return 0;
}