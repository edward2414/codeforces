#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXN = 100 + 5;

int main()
{
	int m, n; cin >> m >> n;
	int a[MAXN][MAXN], b[MAXN][MAXN];
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = 1;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &b[i][j]);
   			if(!b[i][j])
   			{
   				for(int ii = 1; ii <= m; ii++)
   					a[ii][j] = 0;
   				for(int jj = 1; jj <= n; jj++)
   					a[i][jj] = 0;
   			}
		}
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
		{
			int flag = 0;
			for(int ii = 1; ii <= m; ii++)
			{
				if(a[ii][j])
				{
					flag = 1;
					break;
				}
			}
			for(int jj = 1; jj <= n; jj++)
			{
				if(a[i][jj])
				{
					flag = 1;
					break;
				}
			}
			if(b[i][j] != flag)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	cout << "YES" << endl;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j < n; j++)
			cout << a[i][j] << ' ';
		cout << a[i][n] << endl;
	}
}