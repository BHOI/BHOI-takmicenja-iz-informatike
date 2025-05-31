#include <iostream>
#include <cassert>

using namespace std;

int MaxUcinak(int n, int k, int p, int s, int* poeni);

int main() {
  int n, k, p, s;
  cin >> n >> k >> p >> s;
  int* poeni = new int [n * k];
  for (int i = 0; i < n * k; i++)
      cin >> poeni[i];
  cout << MaxUcinak(n, k, p, s, poeni) << endl;
  return 0;
}

