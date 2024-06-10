#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

int helper(int fromCap, int toCap, int d)
{
  int from = fromCap;
  int to = 0;

  int step = 1;

  while ((from + to) != d)
  {
    int temp = min(from, toCap - to);

    to += temp;
    from -= temp;

    step++;

    if (from == 0)
    {
      from = fromCap;
      step++;
    }
    if ((from + to) == d)
      break;

    if (to == toCap)
    {
      to = 0;
      step++;
    }
  }
  return step;
}

int solve(int m, int n, int d)
{
  if (d == 0)
  {
    return 0;
  }
  if (m + n == d)
  {
    return 2;
  }
  if (m > n)
  {
    swap(m, n);
  }
  if (d > (n + m))
    return -1;

  if (d % __gcd(n, m) != 0)
    return -1;

  return min(helper(n, m, d), helper(m, n, d));
}

int main()
{
  int a, b, c;

  cin >> a >> b >> c;
  cout << solve(a, b, c) << endl;
  return 0;
}