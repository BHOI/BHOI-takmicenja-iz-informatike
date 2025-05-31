#include "fstream"
#include "iostream"
#include "vector"

using namespace std;

long f(vector<int>& a, vector<int>& b, int k)
{
  if (k < 0) return 0;
  long d = 0;
  for (int i = 1; i < (int) b.size(); ++i)
    if (b[i] - b[i - 1] > k * 2) d += b[i] - b[i - 1] - k * 2;
  long ans = 0;
  for (int i = 1; i < (int) a.size(); ++i)
    if (a[i] - a[i - 1] > k * 2) ans += d * (a[i] - a[i - 1] - k * 2);
  return ans;
}

long VelicinaZone(int w, int h, int n, int *a, int m, int *b, int k1 ,int k2)
{
  vector<int> loc_a, loc_b;
  loc_a.resize(n + 2);
  loc_b.resize(m + 2);
  for (int i = 0; i < n; ++i) loc_a[i + 1] = a[i];
  for (int i = 0; i < m; ++i) loc_b[i + 1] = b[i];
  loc_a[0] = 0;
  loc_b[0] = 0;
  loc_a[n + 1] = h;
  loc_b[m + 1] = w;
  return (f(loc_a, loc_b, k1) - f(loc_a, loc_b, k2 + 1));
}

