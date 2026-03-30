#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> d(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> d[i][j];

  vector<vector<char>> odabrano(n, vector<char>(m, '.'));
  long long ukupno = 0;

  // Obrada traka. Redovi su interno 0-indeksirani.
  // 1-indeksirani redovi 3,6,9,... su nule => 0-indeksirani redovi 2,5,8,...
  // Trake: {0,1}, {3,4}, {6,7}, ... i eventualno pojedinacni redovi na kraju.
  int r = 0;
  while (r < n) {
    if ((r + 1) % 3 == 0) {
      // Ovaj red je nula-red, preskoci ga.
      r++;
      continue;
    }

    // Odredi traku: 1 ili 2 reda.
    int r0 = r;
    int redova_u_traci = 1;
    if (r + 1 < n && (r + 2) % 3 != 0) {
      // Sljedeci red nije nula-red i dio je ove trake.
      // Traka ima najvise 2 reda (jer je svaki 3. nula).
      redova_u_traci = 2;
    }

    if (redova_u_traci == 1) {
      // Traka od jednog reda: klasicni 1D DP
      vector<long long> dp(m);
      vector<bool> uzmi(m, false);

      dp[0] = d[r0][0];
      uzmi[0] = true;
      if (m > 1) {
        if (d[r0][1] > dp[0]) {
          dp[1] = d[r0][1];
          uzmi[1] = true;
        } else {
          dp[1] = dp[0];
          uzmi[1] = false;
        }
      }
      for (int j = 2; j < m; j++) {
        if (dp[j - 2] + d[r0][j] > dp[j - 1]) {
          dp[j] = dp[j - 2] + d[r0][j];
          uzmi[j] = true;
        } else {
          dp[j] = dp[j - 1];
          uzmi[j] = false;
        }
      }

      ukupno += dp[m - 1];

      // Rekonstrukcija
      int j = m - 1;
      while (j >= 0) {
        if (uzmi[j]) {
          odabrano[r0][j] = '*';
          j -= 2;
        } else {
          j--;
        }
      }
    } else {
      // Traka od dva reda: DP sa 3 stanja po koloni
      // Stanje 0: nista odabrano
      // Stanje 1: gornji red odabran
      // Stanje 2: donji red odabran
      int r1 = r0 + 1;

      vector<array<long long, 3>> dp(m);
      vector<array<int, 3>> prethodni(m); // cuva prethodno stanje

      dp[0][0] = 0;
      dp[0][1] = d[r0][0];
      dp[0][2] = d[r1][0];

      prethodni[0] = {-1, -1, -1};

      for (int j = 1; j < m; j++) {
        // Stanje 0: nista odabrano u koloni j
        // Moze doci iz bilo kojeg stanja u koloni j-1
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

        // Stanje 1: gornji red odabran u koloni j
        // Ne moze doci iz stanja 1 (horizontalna susjednost u gornjem redu)
        dp[j][1] = dp[j - 1][0] + d[r0][j];
        prethodni[j][1] = 0;
        if (dp[j - 1][2] + d[r0][j] > dp[j][1]) {
          dp[j][1] = dp[j - 1][2] + d[r0][j];
          prethodni[j][1] = 2;
        }

        // Stanje 2: donji red odabran u koloni j
        // Ne moze doci iz stanja 2 (horizontalna susjednost u donjem redu)
        dp[j][2] = dp[j - 1][0] + d[r1][j];
        prethodni[j][2] = 0;
        if (dp[j - 1][1] + d[r1][j] > dp[j][2]) {
          dp[j][2] = dp[j - 1][1] + d[r1][j];
          prethodni[j][2] = 1;
        }
      }

      // Pronadji najbolje zavrsno stanje
      int najbolje_stanje = 0;
      if (dp[m - 1][1] > dp[m - 1][najbolje_stanje]) najbolje_stanje = 1;
      if (dp[m - 1][2] > dp[m - 1][najbolje_stanje]) najbolje_stanje = 2;

      ukupno += dp[m - 1][najbolje_stanje];

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

    r += redova_u_traci;
  }

  cout << ukupno << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << odabrano[i][j];
    cout << "\n";
  }
}
