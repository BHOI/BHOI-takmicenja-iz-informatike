#include <iostream>
#include <cassert>

using namespace std;

long VelicinaZone(int W, int H, int N, int *A, int M, int *B, int K1, int K2);

int main() {
  int W, H, K1, K2, N, M;
  cin >> W >> H;
  cin >> K1 >> K2;
  cin >> N >> M;
  int *A, *B;
  A = new int [N];
  B = new int [M];
  for (int i = 0; i < N; ++i) 
    cin >> A[i];
  for (int i = 0; i < M; ++i) 
    cin >> B[i];
  cout << VelicinaZone(W, H, N, A, M, B, K1, K2) << endl;
  return 0;
}
