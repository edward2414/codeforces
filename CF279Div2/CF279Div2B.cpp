#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	const int MAXN = 2e5 + 5, MAXNUM = 1e6 + 5;
	int n, a[MAXN], b[MAXN];
	cin >> n;
	int c[MAXNUM][3];
	int head, tail, maxval = 0;
	memset(c, -1, sizeof(c));
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", a+i, b+i);
		maxval = max(maxval, a[i]);
		maxval = max(maxval, b[i]);
		c[a[i]][1] = b[i]; c[b[i]][0] = a[i];
		if(a[i] == 0) head = i;
		if(b[i] == 0) tail = i;
	}
	int ans[MAXN];
	if(n&1)
	{
		int flag[MAXNUM], cnt[MAXNUM];
		memset(flag, 0, sizeof(flag));
		memset(cnt, 0, sizeof(cnt));
		int i = 2, temp = b[head];
		while(i <= n)
		{
			flag[temp] = 1;
			ans[i] = temp;
			temp = c[temp][1];
			i += 2;
		}
		for(int j = 1; j <= n; j++)
		{
			if(!flag[a[j]] && a[j])
			{
				cnt[a[j]]++;
			}
			if(!flag[b[j]] && b[j])
			{
				cnt[b[j]]++;
			}
		}
		int head2;
		for(int j = 1; j <= n; j++)
		{
			if(cnt[a[j]] == 1)
			{
				head2 = a[j];
			 	break;
			}
		}
		i = 1;
		while(i <= n)
		{
			ans[i] = head2;
			head2 = c[head2][1];
			i += 2;
		}
		for(int i = 1; i < n; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
	}else{
		int i = 2, temp = b[head];
		while(i <= n)
		{
			ans[i] = temp;
			temp = c[temp][1];
			i += 2;
		}
		i = n - 1;
		temp = a[tail];
		while(i >= 1)
		{
			ans[i] = temp;
			temp = c[temp][0];
			i -= 2;
		}
		for(int i = 1; i < n; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
	}
}