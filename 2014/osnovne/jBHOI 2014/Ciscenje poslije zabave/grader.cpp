#include <cstdio>
#include <cassert>

using namespace std;

int Raspodjela(int N, int* T);

int main() {
  int N;
  scanf("%d", &N);
  int* T = new int [N];
  for (int i = 0; i < N; i++)
      scanf("%d", &T[i]);
  printf("%d\n", Raspodjela(N, T));
  return 0;
}
