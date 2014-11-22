#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int hp1, a1, d1, hp2, a2, d2, h, a, d;
	int th, ta, td, ans = 1e7;
	cin >> hp1 >> a1 >> d1 >> hp2 >> a2 >> d2 >> h >> a >> d;
	for(int j = 0; a1 + j <= 200; j++)
		for(int k = 0; d1 + k <= 100; k++)
		{
			if(a1 + j <= d2) continue;
			if(d1 + k >= a2)
			{
				ans = min(ans, j*a + k*d);
				continue;
			}
			int da1 = a1 + j - d2, da2 = a2 - d1 - k;
			int mTime = (hp2 + da1 - 1) / da1;
			int i = max(da2*mTime - hp1 + 1, 0);
			ans = min(ans, i*h + j*a + k*d);
		}
	cout << ans << endl;
}