#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int MaxUcinak(int n, int k, int p, int s, int* poeni);

int main() {
  int n, k, p, s, i;
  scanf("%d %d %d %d", &n, &k, &p, &s);
  int* poeni = (int*) malloc(n * k * sizeof(int));
  for (i = 0; i < n * k; i++)
      scanf("%d", &poeni[i]);
  printf("%d\n", MaxUcinak(n, k, p, s, poeni));
  return 0;
}
