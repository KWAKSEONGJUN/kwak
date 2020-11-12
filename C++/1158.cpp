#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K, cnt=1;
	scanf("%d %d", &N, &K);
	queue<int> q;

	for(int i=1; i<=N; i++)
	{
		q.push(i);
	}

	printf("<");
	while(!q.empty())
	{
		if(cnt % K == 0)
		{
			printf("%d", q.front());
			if(cnt / K != N) printf(", ");
			q.pop();

		}
		else
		{
			q.push(q.front());
			q.pop();
		}
		cnt++;
	}
	printf(">\n");

	return 0;
}
