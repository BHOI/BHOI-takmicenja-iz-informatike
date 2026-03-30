#include <iostream>
#include <vector>

using namespace std;

// Samo M=1: svaki 3. red je 0, pa se kolona dijeli na parove.
// Uzmi veci iz svakog para. (5 bodova)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> d(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> d[i][j];

  if (m != 1) {
    cout << 0 << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << '.';
      cout << "\n";
    }
    return 0;
  }

  long long ukupno = 0;
  vector<char> odabrano(n, '.');

  int i = 0;
  while (i < n) {
    if ((i + 1) % 3 == 0) {
      // Nula-red, preskoci
      i++;
      continue;
    }

    int r0 = i;
    bool ima_par = (i + 1 < n && (i + 2) % 3 != 0);

    if (!ima_par) {
      // Samo jedan red u traci — uzmi ga
      ukupno += d[r0][0];
      odabrano[r0] = '*';
      i++;
    } else {
      // Par: uzmi veci
      int r1 = i + 1;
      if (d[r0][0] >= d[r1][0]) {
        ukupno += d[r0][0];
        odabrano[r0] = '*';
      } else {
        ukupno += d[r1][0];
        odabrano[r1] = '*';
      }
      i += 2;
    }
  }

  cout << ukupno << "\n";
  for (int i = 0; i < n; i++)
    cout << odabrano[i] << "\n";
}
