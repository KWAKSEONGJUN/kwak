#include <iostream>

using namespace std;



int arr[301];


int func(int a, int b)
{
	int res;
	if(arr[a] == 0)
	{
		return 1;
	}
	else if(arr[a] == b)
	{
		return 2;
	}
	else
	{
		res = func(arr[a], b);
	}

	return res;

}

int main()
{
	int n, m, q;
	pair<int, int> r;
	scanf("%d %d %d", &n, &m, &q);



	
	for(int i=0; i<301; i++)
	{
		arr[i] = 0;
	}

	for(int i=0; i<m; i++)
	{
		scanf("%d %d", &r.first, &r.second);
		arr[r.second] = r.first;
	}

	int f, s;
	for(int i=0; i<q; i++)
	{
		scanf("%d %d", &f, &s);

		int res = func(f, s);

		if(res == 1) 
		{
			res = func(s, f);
			if(res == 1) printf("<>\n");
			else if(res == 2) printf("->\n");
		}
		else if(res == 2) 
		{
			printf("<-\n");
		}
	}


	return 0;
}