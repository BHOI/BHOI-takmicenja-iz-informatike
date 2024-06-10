#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>

using namespace std;

const int N = 200005;

int n;
vector <bool> used;
vector <int> st, pd;
vector <int> adj[N];

void init(int u, int d) {
  st.push_back(u);
  if (int(st.size()) - d >= 0) {
    pd[u] = st[(int) st.size() - d];
  }
  for (int v : adj[u]) {
    init(v, d);
  }
  st.pop_back();
}

void dfs(int u) {
  used[u] = true;
  for (int v : adj[u]) {
    if (!used[v]) {
      dfs(v);
    }
  }
}

int get(int x) {
  pd.assign(n + 1, -1);
  init(1, x);

  vector <int> vec;
  vector <int> h(n + 1);
  queue <int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vec.push_back(u);
    for (int v : adj[u]) {
      h[v] = h[u] + 1;
      q.push(v);
    }
  }
  reverse(vec.begin(), vec.end());

  used.assign(n + 1, 0);
  int ans = 0;
  for (int u : vec) {
    if (!used[u] && h[u] > x) {
      ans++;
      dfs(pd[u]);
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    int k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      adj[p].push_back(i);
    }

    int l = 1, r = n - 1, ans = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (get(mid) <= k) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    for (int i = 1; i <= n; i++) {
      adj[i].clear();
    }
    cout << ans << endl;
  }
  return 0;
}
