#include <bits/stdc++.h>

using namespace std;

int n, m;
int ksj[501][501];
bool v[501][501];
pair<int, int> res = {0, 0};
int mx = 0;

int main()
{
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			scanf("%d", &ksj[i][j]);
		}
	}

	queue<pair<int, int>> q;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(ksj[i][j] && !v[i][j])
			{
				q.push({i, j});
				v[i][j] = true;
				while(!q.empty())
				{
					int len = q.size();

					while(len--)
					{
						pair<int, int> tmp = q.front();
						q.pop();

						if(tmp.first - 1 >= 0 && ksj[tmp.first-1][tmp.second] && !v[tmp.first-1][tmp.second])
						{
							q.push({tmp.first-1, tmp.second});
							v[tmp.first-1][tmp.second] = true;
						}
						if(tmp.first + 1 < n && ksj[tmp.first+1][tmp.second] && !v[tmp.first+1][tmp.second])
						{
							q.push({tmp.first+1, tmp.second});
							v[tmp.first+1][tmp.second] = true;
						}
						if(tmp.second - 1 >= 0 && ksj[tmp.first][tmp.second-1] && !v[tmp.first][tmp.second-1])
						{
							q.push({tmp.first, tmp.second-1});
							v[tmp.first][tmp.second-1] = true;
						}
						if(tmp.second + 1 < m && ksj[tmp.first][tmp.second+1] && !v[tmp.first][tmp.second+1])
						{
							q.push({tmp.first, tmp.second+1});
							v[tmp.first][tmp.second+1] = true;
						}

						mx++;
					}
				}
				res.second = max(mx, res.second);
				mx = 0;
				res.first++;
			}
		}
	}

	printf("%d\n%d", res.first, res.second);

	return 0;
}