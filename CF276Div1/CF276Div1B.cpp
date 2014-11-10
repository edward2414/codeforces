//An usage of lower_bound
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAXN 200000
#define MAXVAL 1000000
using namespace std;
int main()
{
    int n, a[MAXN+5], checked[MAXVAL + 5], maxn = 0;
    memset(checked, 0, sizeof(checked));
    scanf("%d", &n);
    for(int i = 0; i != n; i++)
    {
        scanf("%d", a+i);
        checked[a[i]] = 1;
        maxn = max(maxn, a[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= MAXVAL; i++)
    {
        if(checked[i])
        {
            a[cnt++] = i;
        }
    }

    sort(a, a+cnt);

    int ans = 0;
    for(int i = 0; i != cnt; i++)
    {
        for(int j = a[i]; j <= 2*maxn; j+=a[i])
        {
            int index = lower_bound(a, a+cnt, j) - a - 1;
            if(index == cnt-1) break;
        }
    }
    cout << ans << endl;
}
