#include <cstdio>
#include <cstring>

#define MAXN 300005
#define MAXL 300005

int N, M, A, B;
int uf[MAXL];
int taken[MAXL];

int find(int n) { return uf[n] == n ? n : uf[n] = find(uf[n]); }

void unite(int a, int b) { 
  puts("DA");
  uf[find(a)] = find(b); 
} 

int main(void)
{
  scanf("%d%d", &N, &M);

  for (int i = 1; i <= M; ++i)
    uf[i] = i;

  for (int i = 0; i < N; ++i) {
    scanf("%d%d", &A, &B);

    if (!taken[A]) {
      taken[A] = 1;
      unite(A, B);
    }
    else if (!taken[B]) {
      taken[B] = 1;
      unite(B, A);
    }
    else if (!taken[find(A)]) {
      taken[find(A)] = 1;
      unite(A, B);
    }
    else if (!taken[find(B)]) {
      taken[find(B)] = 1;
      unite(B, A);
    }
    else {
      puts("NE");
    }
  }

  return 0;
}
