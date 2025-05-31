#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int MaksimalnaVrijednost(int N, int M, int* T);

int main() {
  int N, M, i;
  scanf("%d", &N);
  scanf("%d", &M);
  int* T = (int*) malloc(N * M * sizeof(int));
  for (i = 0; i < N * M; i++)
      scanf("%d", &T[i]);
  printf("%d\n", MaksimalnaVrijednost(N, M, T));
  return 0;
}




