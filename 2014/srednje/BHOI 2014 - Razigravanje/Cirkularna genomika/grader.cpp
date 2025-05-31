#include <iostream>
#include <cassert>

using namespace std;

int BakterijaSlicnost(int N, char *A, char *B);

int main() {
  int N;
  cin >> N;
  char *A, *B;
  A = new char [N];
  B = new char [N];
  for (int i = 0; i < N; ++i) 
    cin >> A[i];
  for (int i = 0; i < N; ++i) 
    cin >> B[i];
  cout << BakterijaSlicnost(N, A, B) << endl;
  return 0;
}
