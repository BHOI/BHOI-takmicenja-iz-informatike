#include <iostream>
#include <cassert>

using namespace std;

int BrojMinimalnihPotrosnji(int r, int p, int q, int v, int e, int* energije);

int main() {
  int r, p, q, v, e;
  cin >> r >> p >> q >> v >> e;
  int* energije = new int[e * 3];
  for (int i = 0; i < e * 3; i++)
      cin >> energije[i];
  cout << BrojMinimalnihPotrosnji(r, p, q, v, e, energije) << endl;
  return 0;
}
