#include <cstdio>
#include <cassert>

using namespace std;

#define inbuf_len 1 << 23
#define outbuf_len 1 << 10

void Inicijalizacija(int n, int m[]);
void PostaviKucu(int i, int x, int y);
int Povezi();

int main() {
  int n, dummy;
  
  /* Set input and output buffering */
  char *inbuf, *outbuf;
  inbuf = new char[inbuf_len];
  outbuf = new char[outbuf_len];
  dummy = setvbuf(stdin, inbuf, _IOFBF, inbuf_len);
  assert(dummy == 0);
  dummy = setvbuf(stdout, outbuf, _IOFBF, outbuf_len);
  assert(dummy == 0);
  
  dummy = scanf("%d", &n);
  int *m = new int[n];
  for (int i = 0; i < n; i++)
    dummy = scanf("%d", &m[i]);
  Inicijalizacija(n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m[i]; j++) {
      int x, y;
      dummy = scanf("%d %d", &x, &y);
      PostaviKucu(i, x, y);
    }
  dummy = printf("%d\n", Povezi());
  return 0;
}

