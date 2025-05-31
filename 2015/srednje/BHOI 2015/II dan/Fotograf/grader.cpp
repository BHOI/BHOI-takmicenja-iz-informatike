#include <cstdio>

int main()
{
  int Vrh(int,int);
  void Drvece(int,int[]);
  int N;
  scanf("%d", &N);
  int h[100010];
  for (int i = 0; i < N; ++i)
    scanf("%d", h + i);
  Drvece(N, h);
  int M;
  scanf("%d", &M);
  for(int i = 0; i < M; ++i) {
    int L, D;
    scanf("%d%d", &L, &D);
    printf("%d\n", Vrh(L, D));
  }
  return 0;
}
