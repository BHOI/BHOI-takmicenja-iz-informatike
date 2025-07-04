#include <bits/stdc++.h>

using namespace std;

int simulate(const vector<long double> &d, int a, int b) {
  int p1 = a - 1, p2 = a + 1, last = a;
  int x = 0;
  if (last == b) return x;
  x++;
  while (p1 != -1 || p2 != d.size()) {
    if (p1 != -1 && p2 != d.size()) {
      if (d[p1] < d[p2]) {
        last = p1;
        p1--;
      } else {
        last = p2;
        p2++;
      }
    } else if (p1 != -1) {
      last = p1;
      p1--;
    } else if (p2 != d.size()) {
      last = p2;
      p2++;
    } else {
      throw;
    }
    if (last == b) return x;
    x++;
  }
  throw;
}

long double enhance(int e, set<long double>& d_sorted, long double old_value) {
  int count = 1;
  long double last = 1e6;  // u slucaju da je e=1
  auto it = --d_sorted.end();  // zadnji element
  for (; it != d_sorted.begin() && count < e; count++, --it) {
    last = *it;
  }
  long double new_value = (*it+last)/2.;
  assert(d_sorted.erase(old_value) == 1);
  d_sorted.insert(new_value);
  return new_value;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a;
  cin >> n >> a;
  a--;
  vector<long double> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  set<long double> d_sorted(d.begin(), d.end());

  int q;
  cin >> q;
  while (q--) {
    char c;
    cin >> c;
    if (c == 'F') {
      int b;
      cin >> b;
      b--;
      cout << simulate(d, a, b) << endl;
    } else if (c == 'E') {
        int p, e;
        cin >> p >> e;
        p--;
        d[p] = enhance(e, d_sorted, d[p]);
    } else {
      throw;
    }
  }
}