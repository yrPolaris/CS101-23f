#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    long long hexnum = 0;
    int m = 0;
    int count = 0;
    long long pow = 1;
    scanf("%lld%d", &hexnum, &m);
    int res1[70] = {0};
    int res2[70] = {0};
    int res[70] = {0};
    int a = 0;
    int idx = 0;
    while (hexnum != 0)
    {
        a = hexnum % 2;
        hexnum = hexnum / 2;
        res2[idx] = a;
        idx ++;
    }
    for (int i = 0; i < idx; i++)
    {
        res1[idx - 1 - i] = res2[i];
    }
    for (int i = 0; i < m+1; i++)
    {
        res[i] = res1[idx - m - 1 + i];
    }
    for (int i = m+1; i < idx; i++)
    {
        res[i] = res1[i - m - 1];
    }
    for (int i = 0; i < idx; i++)
    {
        hexnum = hexnum + res[idx - i - 1] * pow;
        pow *= 2;
    }
    for (int i = 0; i < idx; i++)
    {
        if (res[idx - i - 1] == 0)
        {
            count ++;
        }
        if (res[idx - i - 1] == 1)
        {
            break;
        }
    }
    printf("%lld",hexnum);
    printf(" ");
    printf("%d", count);
    return 0;
}