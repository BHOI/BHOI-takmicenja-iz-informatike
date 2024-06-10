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
int arr[N];
int idx[N];
bool used[N];
vector <int> adj[N];
vector <int> vec;

inline bool cmp(const int &a, const int &b) {
  return (idx[a] < idx[b]);
}

void bfs() {
  queue <int> q;
  q.push(1);
  used[1] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    vec.push_back(u);
    used[u] = true;
    for (int v : adj[u]) {
      if (!used[v]) {
        q.push(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    idx[arr[i]] = i;
  }
  for (int i = 0; i < N; i++) {
    sort(adj[i].begin(), adj[i].end(), cmp);
  }
  bfs();
  bool ok = true;
  if (vec.size() != n) {
    ok = false;
  } else {
    for (int i = 0; i < n; i++) {
      ok &= (vec[i] == arr[i]);
    }
  }
  if (ok) {
    cout << "DA" << endl;
  } else {
    cout << "NE" << endl;
  }
  return 0;
}
