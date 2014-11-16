//an usage of fast power
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n, m;
int x[MAXN], origin[MAXN], temp[MAXN];

int* multi(int *a, int *b)
{
    int *c;
    for(int i = 0; i != n; i++)
    {
        c[i] = a[b[i]];
    }
    return c;
}

int main()
{
    char s[MAXN], ss[MAXN];
    scanf("%s", s);
    n = strlen(s);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        int d, k; scanf("%d %d", &k, &d);
        int cnt = 0, tk = 0;
        while(cnt < k)
        {
            for(int td = tk; td < k; td += d)
            {
                origin[cnt++] = td;
            }
            tk++;
        }
        for(int j = cnt; j < n; j++)
        {
            origin[j] = j;
        }
        origin[n] = origin[0];
        for(int j = 0; j != n; j++)
        {
            origin[j] = origin[j+1];
            x[j] = j;
        }
        int y = n-k+1;
        while(y)
        {
            if(y & 1)
            {
                for(int j = 0; j != n; j++)
                {
                    temp[j] = x[origin[j]];
                }
                for(int j = 0; j != n; j++)
                {
                    x[j] = temp[j];
                }
            }
            for(int j = 0; j != n; j++)
            {
                temp[j] = origin[origin[j]];
            }
            for(int j = 0; j != n; j++)
            {
                origin[j] = temp[j];
            }
            y >>= 1;
        }
        for(int j = 0; j != n; j++)
        {
            origin[j] = x[(j + k-1) % n];
            ss[j] = s[origin[j]];
            putchar(ss[j]);
        }
        puts("");
        for(int j = 0; j != n; j++)
        {
            s[j] = ss[j];
        }
    }
}
