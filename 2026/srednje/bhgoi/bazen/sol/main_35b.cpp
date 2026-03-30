#include <iostream>
#include <vector>

using namespace std;

// 1D DP: rjesava N=1 za bilo koji M. (35 bodova)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> d(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> d[i][j];

  if (n != 1) {
    cout << 0 << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << '.';
      cout << "\n";
    }
    return 0;
  }

  // DP po redu
  vector<long long> dp(m);
  vector<bool> uzmi(m, false);

  dp[0] = d[0][0];
  uzmi[0] = true;
  if (m > 1) {
    if (d[0][1] > dp[0]) {
      dp[1] = d[0][1];
      uzmi[1] = true;
    } else {
      dp[1] = dp[0];
    }
  }
  for (int j = 2; j < m; j++) {
    if (dp[j - 2] + d[0][j] > dp[j - 1]) {
      dp[j] = dp[j - 2] + d[0][j];
      uzmi[j] = true;
    } else {
      dp[j] = dp[j - 1];
    }
  }

  cout << dp[m - 1] << "\n";

  // Rekonstrukcija
  vector<char> odabrano(m, '.');
  int j = m - 1;
  while (j >= 0) {
    if (uzmi[j]) {
      odabrano[j] = '*';
      j -= 2;
    } else {
      j--;
    }
  }
  for (int j = 0; j < m; j++)
    cout << odabrano[j];
  cout << "\n";
}
