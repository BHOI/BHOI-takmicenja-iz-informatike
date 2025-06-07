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

const int N = 1005;

bool mat[N][N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    mat[x][y] = 1;
  }
  int ans = 0;
  int m = 1000; // maksimalna velicina matrice
  for (int i = 1; i <= m; i++) {
    int have = 0;
    int x = i, y = 1;
    while (1 <= x && x <= m && 1 <= y && y <= m) {
      if (mat[x][y]) {
        ans += have;
        have++;
      }
      x++;
      y++;
    }
  }
  for (int i = 2; i <= m; i++) { // Od 2 da izbjegnemo ponavljanje
    int have = 0;
    int x = 1, y = i;
    while (1 <= x && x <= m && 1 <= y && y <= m) {
      if (mat[x][y]) {
        ans += have;
        have++;
      }
      x++;
      y++;
    }
  }
  for (int i = m; i >= 1; i--) {
    int have = 0;
    int x = i, y = 1;
    while (1 <= x && x <= m && 1 <= y && y <= m) {
      if (mat[x][y]) {
        ans += have;
        have++;
      }
      x--;
      y++;
    }
  }
  for (int i = 2; i <= m; i++) {
    int have = 0;
    int x = m, y = i;
    while (1 <= x && x <= m && 1 <= y && y <= m) {
      if (mat[x][y]) {
        ans += have;
        have++;
      }
      x--;
      y++;
    }
  }
  cout << ans << endl;
  return 0;
}


