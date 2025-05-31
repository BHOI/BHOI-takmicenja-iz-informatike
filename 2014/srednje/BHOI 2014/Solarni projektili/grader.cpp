#include <iostream>
#include <cassert>

using namespace std;

int BrojSudara(int n, int* staze);

int main() {
  int n;
  cin >> n;
  int* staze = new int [n * 5];
  for (int i = 0; i < n * 5; i++)
      cin >> staze[i];
  cout << BrojSudara(n, staze) << endl;
  return 0;
}

