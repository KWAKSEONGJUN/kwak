#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, P, res=0;
	scanf("%d %d", &N, &P);

	vector<stack<int>> v(7);
	pair<int, int> melody;

	for(int i=0; i<N; i++)
	{
		int flag = 0;

		scanf("%d %d", &melody.first, &melody.second);
		if(v[melody.first].size() <= 0)
		{
			res++;
			v[melody.first].push(melody.second);
		}
		else if(v[melody.first].top() > melody.second)
		{	
			while(!v[melody.first].empty() && v[melody.first].top() > melody.second)
			{
				v[melody.first].pop();
				res++;
			}
			
			if(!v[melody.first].empty() && v[melody.first].top() == melody.second)
				;
			else 
			{
				res++;
				v[melody.first].push(melody.second);
			}

		}
		else if(v[melody.first].top() < melody.second)
		{
			v[melody.first].push(melody.second);
			res++;
		}
		
	}

	printf("%d\n", res);

	return 0;
}