#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	int a[10];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n == 0)
	{
		cout << "YES\n1\n1\n3\n3" << endl;
	}else if(n == 4){
		sort(a+1, a+5);
		if(a[4] == 3*a[1] && a[1] + a[4] == a[2] + a[3])
		{
			cout << "YES" << endl;
		}else
		{
			cout << "NO" << endl;
		}
	}else if(n == 1){
		cout << "YES" << endl
		     << a[1] << endl
		     << 3*a[1] << endl
		     << 3*a[1] << endl;
	}else if(n == 3){
		int maxa = max(max(a[1], a[2]), a[3]), flag = 0;
		int b[] = {0, a[1], a[2], a[3]};
		for(int i = 1; i <= 3*b[3]; i++)
		{
			a[4] = i;
			sort(a+1, a+5);
			if(a[4] == 3*a[1] && a[1] + a[4] == a[2] + a[3])
			{
				flag = i;
				break;
			}
			a[1] = b[1]; a[2] = b[2]; a[3] = b[3];
		}
		if(flag)
		{
			cout << "YES\n" << flag << endl;
		}else
		{
			cout << "NO" << endl;
		}
	}else if(n == 2){
		int mina = min(a[1], a[2]), maxa = max(a[1], a[2]);
	    if(mina * 3 == maxa){
	        cout << "YES\n" << mina << endl << maxa << endl;
		}else if(mina == maxa){
			cout << "YES\n" << mina * 3 << endl << mina * 3 << endl;
		}else if(mina * 3 < maxa){
			cout << "NO" << endl;
		}else{
			int delta = 3*mina - maxa;
			a[3] = mina + delta; a[4] = 3 * mina;
			cout << "YES\n" << a[3] << endl << a[4] << endl;
		}
	}
}