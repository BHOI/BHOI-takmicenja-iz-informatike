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

map <int, int> add, sub;

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ans += add[x + y];
    ans += sub[x - y];
    add[x + y]++;
    sub[x - y]++;
  }
  cout << ans << endl;
  return 0;
}


