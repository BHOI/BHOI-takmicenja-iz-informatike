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

int n, m;
int ans;
int c[N], d[N];
int kmp[N];
vector <int> a, b;

void initKMP() {
  int i = 1, j = 0;
  while (i < b.size()) {
    while (b[i] == b[j] && i < b.size()) {
      kmp[i] = j + 1;
      i++;
      j++;
    }
    while (b[i] != b[j]) {
      if (j == 0) {
        i++;
        break;
      }
      j = kmp[j - 1];
    }
  }
}

void searchKMP() {
  int i = 0, j = 0;
  while (i < a.size()) {
    while (a[i] == b[j] && i < a.size()) {
      i++;
      j++;
      if (j == b.size()) {
        ans++;
        j = kmp[j - 1];
      }
    }
    while (a[i] != b[j]) {
      if (j == 0) {
        i++;
        break;
      }
      j = kmp[j - 1];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  if (m == 1) { // poseban slucaj
    cout << n << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    a.emplace_back(c[i] - c[i - 1]);
  }
  for (int i = 1; i < m; i++) {
    b.emplace_back(d[i] - d[i - 1]);
  }
  initKMP();
  searchKMP();
  cout << ans << endl;
  return 0;
}
