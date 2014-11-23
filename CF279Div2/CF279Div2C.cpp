#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
	const int MAXN = 1e6 + 5;
	int cnt = 0, a[MAXN];
	char ch = getchar();
	while(ch != '\n')
	{
		a[++cnt] = ch - '0';
		ch = getchar();
	}
	if(cnt == 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	int x, y; cin >> x >> y;
	long long f[MAXN], g[MAXN], ten[MAXN];
	f[0] = 0; ten[0] = 1;
	for(int i = 1; i <= cnt; i++)
	{
		f[i] = (f[i-1] * 10 + a[i]) % x;
		ten[i] = (ten[i-1] * 10) % y;
	}
	g[cnt+1] = 0;
	for(int i = cnt; i >= 1; i--)
	{
		g[i] = (g[i+1] + a[i] * ten[cnt - i]) % y;
	}
	for(int i = 1; i < cnt; i++)
	{
		if(a[i+1])
		{
			if(f[i] == 0 && g[i+1] == 0)
			{
				cout << "YES" << endl;
				for(int j = 1; j <= i; j++)
				{
					printf("%d", a[j]);
				}
				printf("\n");
				for(int j = i + 1; j <= cnt; j++)
				{
					printf("%d", a[j]);
				}
				printf("\n");
				return 0;
			}
		}
	}
	cout << "NO" << endl;
}