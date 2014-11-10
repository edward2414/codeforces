// Binary Search and Recursion
#include <iostream>
using namespace std;

int getBinaryDigit(long long ago)
{
    int ans = 0;
    while(ago)
    {
        ans++;
        ago >>= 1;
    }
    return ans;
}

int getBinaryOne(long long ago)
{
    int ans = 0;
    while(ago)
    {
        if(ago&1) ans++;
        ago >>= 1;
    }
    return ans;
}

long long getAns(long long x, long long y)
{
    int DigitX = getBinaryDigit(x), DigitY = getBinaryDigit(y);
    if(DigitY == getBinaryOne(y)) return y;
    if(DigitY > DigitX) return ((long long)1 << DigitY - 1) - 1;
    int cnt = 0;
    long long t = (long long)1 << DigitX - 1;
    while((x&t) == (y&t) && t > 0)
    {
        cnt++; t >>= 1;
    }
    if(t == 0) return x;
    long long ago = x >> getBinaryDigit(t) << getBinaryDigit(t);
    x &= (t << 1) - 1; y &= (t << 1) - 1;
    return ago + getAns(x, y);
}

int print(long long ago)
{
    int digit = getBinaryDigit(ago);
    long long t = (long long)1 << digit - 1;
    while(t)
    {
        cout << ((ago&t) >> digit - 1);
        t >>= 1; digit--;
    }
    cout << endl;
}

int main()
{
    int n; cin >> n;
    long long L, r;
    while(n--)
    {
        cin >> L >> r;
        cout << getAns(L, r) << endl;
    }
    return 0;
}
