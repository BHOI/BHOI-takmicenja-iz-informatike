#include <iostream>
#include <vector>

using namespace std;

// 1D brute force: N=1, N*M<=20. (12 bodova)

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

  long long najbolje = 0;
  int najbolja_maska = 0;

  for (int maska = 0; maska < (1 << m); maska++) {
    bool ispravno = true;
    long long suma = 0;
    for (int j = 0; j < m; j++) {
      if (maska & (1 << j)) {
        if (j > 0 && (maska & (1 << (j - 1)))) {
          ispravno = false;
          break;
        }
        suma += d[0][j];
      }
    }
    if (ispravno && suma > najbolje) {
      najbolje = suma;
      najbolja_maska = maska;
    }
  }

  cout << najbolje << "\n";
  for (int j = 0; j < m; j++)
    cout << ((najbolja_maska & (1 << j)) ? '*' : '.');
  cout << "\n";
}
