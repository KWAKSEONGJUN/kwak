#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int N, K;
	long long  res = 0;
	string tmp;
	queue<int> q[21];
	scanf("%d %d", &N, &K);

	for(int i=0; i<N; i++)
	{
		cin >> tmp;
		int l = tmp.length();
		while(!q[l].empty())
		{
			if(i - q[l].front() > K)
				q[l].pop();
			else
				break;

		}

		res += q[l].size();
		q[l].push(i);
	}

	
	printf("%lld\n", res);


	return 0;
}