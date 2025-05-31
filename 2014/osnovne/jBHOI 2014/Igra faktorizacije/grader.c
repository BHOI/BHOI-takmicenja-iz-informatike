#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int IgraFaktorizacije(int M, int* P, int N);

int main() {
  int M, N, i;
  scanf("%d %d", &M, &N);
  int* P = (int*) malloc(M * sizeof(int));
  for (i = 0; i < M; i++)
      scanf("%d", &P[i]);
  printf("%d\n", IgraFaktorizacije(M, P, N));
  return 0;
}
