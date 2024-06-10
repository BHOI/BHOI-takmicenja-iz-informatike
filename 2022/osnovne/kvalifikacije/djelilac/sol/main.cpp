#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define MX 100005

int main()
{
    unsigned long long int n, j, i, a[MX];
    scanf("%llu", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%llu", &a[i]);
    }
    sort(a, a + i);
    for (j = 1; j < n; j++)
    {
        if (a[j] % a[0] != 0)
        {
            cout << "-1";
            return 0;
        }
    }
    cout << a[0];
    return 0;
}