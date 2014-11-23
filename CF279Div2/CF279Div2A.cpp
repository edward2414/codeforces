#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	const int MAXN = 5000 + 5;
	int n; cin >> n;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int a[MAXN];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	    if(a[i] == 1) cnt1++;
	    else if(a[i] == 2) cnt2++;
	    else cnt3++;
	}
	int cnt = min(min(cnt1, cnt2), cnt3);
	cout << cnt << endl;
	if(cnt)
	{
		int b[MAXN][5];
		cnt1 = cnt2 = cnt3 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 1) b[++cnt1][1] = i;
			else if(a[i] == 2) b[++cnt2][2] = i;
			else b[++cnt3][3] = i;
		}
		for(int i = 1; i <= cnt; i++)
		{
			cout << b[i][1] << ' ' << b[i][2] << ' ' << b[i][3] << endl;
		}
	}
	return 0;
}