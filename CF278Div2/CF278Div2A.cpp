#include <iostream>
using namespace std;

int have8(int n)
{
	if(n < 0) n = -n;
	while(n)
	{
		if(n%10 == 8)
			return 1;
		n /= 10;
	}
	return 0;
}

int main()
{
	int a, b = 1; cin >> a;
	a++;
	while(!have8(a))
	{
		b++;
		a++;
	}
	cout << b << endl;
}