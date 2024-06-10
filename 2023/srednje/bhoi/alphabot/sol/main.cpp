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

const int N = 1505;
const int M = 26;

int n, q;
string s;
int dp[N][M];

void init() {
  for (int l = 0; l < M; l++) {
    for (int i = 0; i < n; i++) {
      int diff = 0;
      for (int j = i; j < n; j++) {
        diff += (s[j] - 'a' != l);
        dp[diff][l] = max(dp[diff][l], j - i + 1);
      }
    }
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> s >> q;
  init();
  for (int i = 0; i < q; i++) {
    int x;
    char c;
    cin >> x >> c;
    cout << dp[x][c - 'a'] << endl;
  }
  return 0;
}
