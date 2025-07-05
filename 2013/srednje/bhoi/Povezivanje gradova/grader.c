#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define inbuf_len 1 << 23
#define outbuf_len 1 << 10

void Inicijalizacija(int n, int m[]);
void PostaviKucu(int i, int x, int y);
int Povezi();

int main() {
  int n, dummy, i, j;
  
  /* Set input and output buffering */
  char *inbuf, *outbuf;
  inbuf = (char*) malloc(inbuf_len * sizeof(char));
  outbuf = (char*) malloc(outbuf_len * sizeof(char));
  dummy = setvbuf(stdin, inbuf, _IOFBF, inbuf_len);
  assert(dummy == 0);
  dummy = setvbuf(stdout, outbuf, _IOFBF, outbuf_len);
  assert(dummy == 0);
  
  dummy = scanf("%d", &n);
  int *m = malloc(n*sizeof(int));
  for (i = 0; i < n; i++)
    dummy = scanf("%d", &m[i]);
  Inicijalizacija(n, m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m[i]; j++) {
      int x, y;
      dummy = scanf("%d %d", &x, &y);
      PostaviKucu(i, x, y);
    }
  dummy = printf("%d\n", Povezi());
  return 0;
}
