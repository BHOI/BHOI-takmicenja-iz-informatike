#include <cmath>

using namespace std;

bool BaciJaje(int i);

int f(int k, int l[]) {
  int res = 1;
  for (int i = 0; i <= k; ++i)
    res *= l[i];
  return res;
}

int PronadjiSprat(int n, int k) {
  if (k < 0)
    k = (int)ceil(log2(n));
  int *l = new int[k+1];
  int l0 = 1;
  l0 = (int)pow(n, 1./k);
  if (l0 < 2)
    l0 = 2;
  l[0] = 1;
  for (int i = 1; i <= k; ++i)
    l[i] = l0;
  for (int i = 1; f(k, l) < n; ++l[i++]);
  int max = 0;
  for (int i = 1; i <= k; i++) {
    max += l[i] - 1;
    l[i] *= l[i-1];
    if (l[i] >= n)
      k = i;
  }
  int dg = 0, gg = n;
  for (int j = k-1; j >= 0; --j) {
    int i;
    bool dg_postavljena = false;
    for (i = dg + l[j]; i < gg; i += l[j])
      if (BaciJaje(i)) {
        gg = i;
        dg = i - l[j];
        dg_postavljena = true;
        break;
      }
    if (dg_postavljena == false)
      dg = i-l[j];
  }
  delete[] l;
  return dg;
}
