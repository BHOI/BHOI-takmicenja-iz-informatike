#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

int counter [2000100] [26];

bool kGood(int l, int r, int k)
{
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        cnt += ((counter [r] [i] - ((l == 0) ? 0 : counter [l - 1] [i])) > 0);

    return cnt <= k;
}

int kdobar(string s, int k)
{
    int len = s.length();

    for (int i = 0; i < len; i++)
        for (int j = 0; j < 26; j++)
            counter [i] [j] = ((i == 0) ? (j == (s [i] - 'a')) : counter [i - 1] [j]) + (j == (s [i] - 'a'));

    int globalSol = 0;

    for (int i = 0; i < len; i++)
    {
        int sol = 0;
        int left = i;
        int right = len - 1;

        while (right - left > 3)
        {
            int pivot = (left + right) / 2;

            if (kGood(i, pivot, k))
            {
                left = pivot + 1;
                sol = max (sol, pivot - i + 1);
            }
            else
                right = pivot - 1;
        }

        while (left <= right)
        {
            if (kGood(i, left, k))
                sol = max (sol, left - i + 1);
            left++;
        }

        globalSol = max (globalSol, sol);
    }

    return globalSol;
}
/*
int main()
{

    return 0;
}
*/
//7120























































