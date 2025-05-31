#include <cstdio>
#include <cassert>

using namespace std;

int IgraFaktorizacije(int M, int* P, int N);

int main() {
  int M, N;
  scanf("%d %d", &M, &N);
  int* P = new int [M];
  for (int i = 0; i < M; i++)
      scanf("%d", &P[i]);
  printf("%d\n", IgraFaktorizacije(M, P, N));
  return 0;
}
