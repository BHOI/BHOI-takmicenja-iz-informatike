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

int n, x;
int cnt[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    cnt[x]++;
  }
  for (int i = N - 1; i >= 1; i--) {
    if (cnt[i] & 1) {
      if (!cnt[i - 1]) {
        cnt[i]--;
      } else {
        cnt[i]--;
        cnt[i - 1]++;
      }
    }
  }
  long long hang = 0, ans = 0;
  for (int i = N - 1; i >= 1; i--) {
    if (hang && cnt[i] >= 2) {
      cnt[i] -= 2;
      ans += 1ll * i * hang;
      hang = 0;
    }
    int times = cnt[i] / 4;
    ans += 1ll * times * i * i;
    if (cnt[i] % 4 >= 2) hang = i;
  }
  cout << ans << endl;
  return 0;
}
