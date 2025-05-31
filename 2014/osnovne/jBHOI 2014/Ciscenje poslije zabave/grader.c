#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int Raspodjela(int N, int* T);

int main() {
  int N, i;
  scanf("%d", &N);
  int* T = (int*) malloc(N * sizeof(int));
  for (i = 0; i < N; i++)
      scanf("%d", &T[i]);
  printf("%d\n", Raspodjela(N, T));
  return 0;
}
