#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int BrojMinimalnihPotrosnji(int r, int p, int q, int v, int e, int* energije);

int main() {
  int r, p, q, v, e, i;
  scanf("%d %d %d %d %d", &r, &p, &q, &v, &e);
  int* energije = (int*) malloc(e * 3 * sizeof(int));
  for (i = 0; i < e * 3; i++)
      scanf("%d", &energije[i]);
  printf("%d\n", BrojMinimalnihPotrosnji(r, p, q, v, e, energije));
  return 0;
}
