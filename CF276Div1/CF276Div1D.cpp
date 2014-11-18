//A simple DP, BE CAREFUL OF LONG LONG
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define fabs(x) ((x) >= 0 ? (x) : -(x))
using namespace std;
const int MAXN = 1e6 + 5;

int main()
{
	int n; cin >> n;
	int data[MAXN];
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", data+i);
	}
	long long dp[MAXN], ans;
	dp[1] = ans = 0;
	if(n >= 2)
	{
		dp[2] = fabs(data[2] - data[1]);
		ans = dp[2];
	}
	if(n >= 3)
	{
		for(int i = 3; i <= n; i++)
		{
			long long d1 = data[i-1] - data[i-2], d2 = data[i] - data[i-1];
			if(d1 * d2 > 0) dp[i] = dp[i-1] + fabs(d2);
			else dp[i] = max(dp[i-1], dp[i-2] + fabs(d2));
		}
	}
	cout << dp[n] << endl;
}