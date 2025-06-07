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

const int N = 1000005;

int add[4 * N], sub[4 * N];

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ans += add[x + y + N];
    ans += sub[x - y + N];
    add[x + y + N]++;
    sub[x - y + N]++;
  }
  cout << ans << endl;
  return 0;
}


