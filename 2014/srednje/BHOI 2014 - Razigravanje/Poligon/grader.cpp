#include <cassert>
#include <iostream>
#include <cstdio>

using namespace std;

int Povrsina(int V, int S, char **M);

int main() {
  int V, S;
  cin >> V >> S;
  char **M;
  M = new char *[V];
  for (int i = 0; i < V; i++)
    M[i] = new char[S];
  for (int i = 0; i < V; i++)
    for (int j = 0; j < S; j++)
	scanf(" %c", &M[i][j]);
  cout << Povrsina(V, S, M) << endl;
  return 0;
}
