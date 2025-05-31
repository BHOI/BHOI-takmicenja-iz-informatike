#include <cstdio>
#include <cassert>

using namespace std;

int MaksimalnaVrijednost(int N, int M, int* T);

int main() {
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  int* T = new int [N * M];
  for (int i = 0; i < N * M; i++)
      scanf("%d", &T[i]);
  printf("%d\n", MaksimalnaVrijednost(N, M, T));
  return 0;
}
