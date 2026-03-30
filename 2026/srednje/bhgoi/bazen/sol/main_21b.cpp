#include <iostream>
#include <vector>

using namespace std;

// 2D brute force: N*M<=20. (21 bod)

int n, m;
vector<vector<int>> d;
long long najbolje;
vector<vector<bool>> najbolji_odabir, tren_odabir;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void brute_force(int poz, long long suma) {
  if (poz == n * m) {
    if (suma > najbolje) {
      najbolje = suma;
      najbolji_odabir = tren_odabir;
    }
    return;
  }
  int i = poz / m, j = poz % m;
  brute_force(poz + 1, suma);
  bool moze = true;
  for (int smjer = 0; smjer < 4; smjer++) {
    int ni = i + dx[smjer], nj = j + dy[smjer];
    if (ni >= 0 && ni < n && nj >= 0 && nj < m && tren_odabir[ni][nj]) {
      moze = false;
      break;
    }
  }
  if (moze) {
    tren_odabir[i][j] = true;
    brute_force(poz + 1, suma + d[i][j]);
    tren_odabir[i][j] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  d.assign(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> d[i][j];

  najbolje = 0;
  najbolji_odabir.assign(n, vector<bool>(m, false));
  tren_odabir.assign(n, vector<bool>(m, false));
  brute_force(0, 0);

  cout << najbolje << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << (najbolji_odabir[i][j] ? '*' : '.');
    cout << "\n";
  }
}
