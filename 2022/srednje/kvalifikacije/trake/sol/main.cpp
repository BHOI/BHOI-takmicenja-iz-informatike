// O(N log N + Q log N)
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long llint;

const int MAXN = 600100;
const int MAXQ = 300100;
const int LG = 20;
const int inf = 1e9 + 1000;

vector<int> v[MAXN];

int x[MAXN], y[MAXN];
int a[MAXN], b[MAXN];

int qx1[MAXQ], qx2[MAXQ];
int qy1[MAXQ], qy2[MAXQ];
llint ans[MAXQ];

int L[MAXN][LG];
llint D[MAXN][LG];

void assign_parent(int i, int par)
{
  L[i][0] = par;
  D[i][0] = x[par] - x[i] + abs(y[par] - y[i]);
  for (int j = 1; j < LG; ++j)
  {
    L[i][j] = L[L[i][j - 1]][j - 1];
    D[i][j] = D[i][j - 1] + D[L[i][j - 1]][j - 1];
  }
}

llint get_dist(int i, int x2, int y2)
{
  llint ans = 0;
  for (int j = LG - 1; j >= 0; --j)
    if (x[L[i][j]] <= x2)
    {
      ans += D[i][j];
      i = L[i][j];
    }
  ans += x2 - x[i] + abs(y[i] - y2);
  return ans;
}

int main(void)
{
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d %d", &a[i], &b[i]);
  a[n] = inf, b[n] = -inf;

  for (int i = 0; i <= n; ++i)
  {
    x[2 * i] = x[2 * i + 1] = i;
    y[2 * i] = a[i], y[2 * i + 1] = b[i];
  }

  for (int i : {2 * n, 2 * n + 1})
    for (int j = 0; j < LG; ++j)
      L[i][j] = i, D[i][j] = 0;

  for (int i = 0; i < q; ++i)
  {
    scanf("%d %d %d %d", &qy1[i], &qx1[i], &qy2[i], &qx2[i]);
    --qx1[i], --qx2[i];
    if (qx1[i] > qx2[i])
    {
      swap(qx1[i], qx2[i]);
      swap(qy1[i], qy2[i]);
    }
    v[qx1[i]].push_back(i);
  }

  static int Sa[MAXN], Sb[MAXN];
  int atop = 0, btop = 0;

  Sa[atop++] = 2 * n;
  Sb[btop++] = 2 * n + 1;
  for (int i = n - 1; i >= 0; --i)
  {
    auto shoot = [&](int Y)
    {
      int lo = 0, hi = atop - 1;
      while (lo < hi)
      {
        int mid = (lo + hi + 1) / 2;
        if (y[Sa[mid]] <= Y)
          hi = mid - 1;
        else
          lo = mid;
      }

      int ans = Sa[lo];
      lo = 0, hi = btop - 1;
      while (lo < hi)
      {
        int mid = (lo + hi + 1) / 2;
        if (y[Sb[mid]] >= Y)
          hi = mid - 1;
        else
          lo = mid;
      }
      ans = min(ans, Sb[lo]);
      return ans;
    };

    assign_parent(2 * i, shoot(a[i]));
    assign_parent(2 * i + 1, shoot(b[i]));

    for (int j : v[i])
    {
      int id = 2 * n + 2;
      x[id] = i, y[id] = qy1[j];
      assign_parent(id, shoot(qy1[j]));
      ans[j] = get_dist(id, qx2[j], qy2[j]);
    }

    while (b[i] <= y[Sb[btop - 1]])
      btop--;
    while (a[i] >= y[Sa[atop - 1]])
      atop--;
    Sa[atop++] = 2 * i;
    Sb[btop++] = 2 * i + 1;
  }

  for (int i = 0; i < q; ++i)
    printf("%lld\n", ans[i]);
  return 0;
}
