#include <array>
#include <iostream>
#include <vector>

using namespace std;

// 2D DP na jednoj traci: rjesava N<=3 i N=1. (60 bodova)
// NE rjesava opci slucaj sa vise traka.

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> d(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> d[i][j];

  if (n > 3) {
    cout << 0 << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << '.';
      cout << "\n";
    }
    return 0;
  }

  vector<vector<char>> odabrano(n, vector<char>(m, '.'));
  long long ukupno = 0;

  if (n == 1) {
    // 1D DP po redu
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
    ukupno = dp[m - 1];
    int j = m - 1;
    while (j >= 0) {
      if (uzmi[j]) {
        odabrano[0][j] = '*';
        j -= 2;
      } else {
        j--;
      }
    }
  } else {
    // N==2 ili N==3 (red 2 je nula): DP sa 3 stanja po koloni na redovima 0 i 1
    int r0 = 0, r1 = 1;

    vector<array<long long, 3>> dp(m);
    vector<array<int, 3>> prethodni(m);

    dp[0][0] = 0;
    dp[0][1] = d[r0][0];
    dp[0][2] = d[r1][0];
    prethodni[0] = {-1, -1, -1};

    for (int j = 1; j < m; j++) {
      // Stanje 0: nista odabrano u koloni j
      dp[j][0] = dp[j - 1][0];
      prethodni[j][0] = 0;
      if (dp[j - 1][1] > dp[j][0]) {
        dp[j][0] = dp[j - 1][1];
        prethodni[j][0] = 1;
      }
      if (dp[j - 1][2] > dp[j][0]) {
        dp[j][0] = dp[j - 1][2];
        prethodni[j][0] = 2;
      }

      // Stanje 1: gornji red odabran
      dp[j][1] = dp[j - 1][0] + d[r0][j];
      prethodni[j][1] = 0;
      if (dp[j - 1][2] + d[r0][j] > dp[j][1]) {
        dp[j][1] = dp[j - 1][2] + d[r0][j];
        prethodni[j][1] = 2;
      }

      // Stanje 2: donji red odabran
      dp[j][2] = dp[j - 1][0] + d[r1][j];
      prethodni[j][2] = 0;
      if (dp[j - 1][1] + d[r1][j] > dp[j][2]) {
        dp[j][2] = dp[j - 1][1] + d[r1][j];
        prethodni[j][2] = 1;
      }
    }

    // Pronadji najbolje stanje
    int najbolje_stanje = 0;
    if (dp[m - 1][1] > dp[m - 1][najbolje_stanje]) najbolje_stanje = 1;
    if (dp[m - 1][2] > dp[m - 1][najbolje_stanje]) najbolje_stanje = 2;

    ukupno = dp[m - 1][najbolje_stanje];

    // Rekonstrukcija
    int stanje = najbolje_stanje;
    for (int j = m - 1; j >= 0; j--) {
      if (stanje == 1)
        odabrano[r0][j] = '*';
      else if (stanje == 2)
        odabrano[r1][j] = '*';
      if (j > 0)
        stanje = prethodni[j][stanje];
    }
  }

  cout << ukupno << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << odabrano[i][j];
    cout << "\n";
  }
}
