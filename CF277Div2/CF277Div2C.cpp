#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define fabs(x) ((x) > 0 ? (x) : -(x))
using namespace std;
const int MAXN = 1e5 + 5;

int main()
{
	int n, p; cin >> n >> p; getchar();
	char ch;
	int a[MAXN], marked[MAXN], ans = 0;
	memset(marked, 0, sizeof(marked));
	for(int i = 1; i <= n; i++)
	{
		scanf("%c", &ch);
		a[i] = ch - 'a';
	}
	int cnt = 0;
	for(int i = 1; i <= n/2; i++)
	{
		int j = n + 1 - i;
		int min_a = min(a[i], a[j]), max_a = max(a[i], a[j]);
		int temp = min(max_a - min_a, min_a + 26 - max_a);
		if(temp)
		{
			marked[i] = marked[j] = 1;
			cnt++;
		}
		ans += temp;
	}
	if(ans == 0)
	{
		cout << ans << endl;
		return 0;
	}
	int LL, Lr, rL, rr, pL, pr;
	for(int i = 1; i <= n; i++)
	{
		if(marked[i])
		{
			LL = i;
			break;
		}
	}
	for(int i = n; i >= 1; i--)
	{
		if(marked[i])
		{
			rr = i;
			break;
		}
	}
	for(int i = n/2; i >= 1; i--)
	{
		if(marked[i])
		{
			Lr = i;
			break;
		}
	}
	for(int i = n/2 + 1; i <= n; i++)
	{
		if(marked[i])
		{
			rL = i;
			break;
		}
	}
	for(int i = p - 1; i >= 1; i--)
	{
		if(marked[i])
		{
			pL = i;
			break;
		}
	}
	for(int i = p + 1; i <= n; i++)
	{
		if(marked[i])
		{
			pr = i;
			break;
		}
	}
	int minn = 1e6;
	if(1 <= p && p <= LL) ans += Lr - p;
	else if(rr <= p && p <= n) ans += p - rL;
	else if(Lr <= p && p <= n/2) ans += p - LL;
	else if(n/2 <= p && p <= rL) ans += rr - p;
	else if(LL < p && p < Lr){
		 minn = min(minn, p - LL + Lr - LL);
		 minn = min(minn, Lr - p + Lr - LL);
		 ans += minn;
	}else if(rL < p && p < rr){
		 minn = min(minn, p - rL + rr - rL);
		 minn = min(minn, rr - p + rr - rL);
		 ans += minn;
	}
	cout << ans << endl;
}