#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int SumaCifara(int N, int M);

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  printf("%d\n", SumaCifara(N, M));
  return 0;
}
