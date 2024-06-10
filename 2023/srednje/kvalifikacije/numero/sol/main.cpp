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

int main() {
  ios_base::sync_with_stdio(false);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, k;
  string s;
  cin >> n >> k >> s;
  string ans = s;
  for (int i = 0; i < n; i++) {
    ans[i] = ans[i % k];
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] != s[i]) {
      if (ans[i] > s[i]) break;
      for (int j = k - 1; j >= 0; j--) {
        if (ans[j] != '9') {
          ans[j]++;
          for (int z = j + 1; z < k; z++) ans[z] = '0';
          break;
        }
      }
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    ans[i] = ans[i % k];
  }
  cout << n << endl << ans << endl;
  return 0;
}
