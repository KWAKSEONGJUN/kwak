#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int mx = 0, flag = -1;
	int n = s.length();
	char res;
	vector<int> v(52, 0);

	for(int i=0; i<n; i++)
	{
		if(s[i] < 97)
		{
			v[s[i] - 'A']++;
		}
		else
		{
			v[s[i] - 'a']++;
		}
	}
	for(int i=0; i<52; i++)
	{
		if(mx < v[i])
		{
			res = i + 65;
			mx = v[i];
		}
	}
	for(int i=0; i<52; i++)
	{
		if(mx == v[i])
			flag++;
	}
	if(flag > 0)
		printf("?\n");
	else
		printf("%c", res);

	return 0;
}