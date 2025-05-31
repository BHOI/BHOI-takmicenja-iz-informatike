#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int BrojSudara(int n, int* staze);

int main() {
  int n, i;
  scanf("%d", &n);
  int* staze = (int*) malloc(n * 5 * sizeof(int));
  for (i = 0; i < n * 5; i++)
      scanf("%d", &staze[i]);
  printf("%d\n", BrojSudara(n, staze));
  return 0;
}
