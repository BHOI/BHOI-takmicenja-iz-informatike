#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int simulate(const vector<ll>& d, int a, int b) {
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

void enhance(int e, priority_queue<pair<ll, size_t>>& d_sorted, vector<ll>& d,
             int p) {
  vector<pair<ll, int>> top_e;
  top_e.reserve(e);
  int seen = 0;
  for (; seen < e;) {
    auto top = d_sorted.top();
    d_sorted.pop();
    if (top.first != d[top.second]) {
      // just pop out stale values from the queue
      continue;
    }
    seen++;
    top_e.push_back(top);
  }
  auto last_iter = top_e.rbegin();
  // Take the value of the current e'th one an increase by 1 for our number.
  ll last_value = last_iter->first + 1;
  d_sorted.push(*last_iter);
  // Push our now enhanced doll, the old value will be ignored if ever accessed.
  d_sorted.push({last_value, p});
  d[p] = last_value;
  while (++last_iter != top_e.rend()) {
    int i = last_iter->second;
    d[i] = ++last_value;
    d_sorted.push({d[i], i});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a;
  cin >> n >> a;
  a--;
  vector<ll> d(n);
  priority_queue<pair<ll, size_t>> d_sorted;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    d_sorted.push({d[i], i});
  }

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
      enhance(e, d_sorted, d, p);
    } else {
      throw;
    }
  }
}