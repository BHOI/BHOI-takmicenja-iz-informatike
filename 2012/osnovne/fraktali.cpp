#include <iostream>
#include <vector>

using namespace std;

void draw(vector<vector<char> > &buffer, int i, int j, int n)
{
  buffer[i][j] = buffer[i][j+n+1] = buffer[i+n+1][j] = buffer[i+n+1][j+n+1] = buffer[i][j+2*n+2] = buffer[i+2*n+2][j] ='+';
  buffer[i+n+1][j+2*n+2] = buffer[i+2*n+2][j+n+1] = buffer[i+2*n+2][j+2*n+2] = '+';
  for (int k = 1; k <= n; ++k)
  {
    buffer[i][j+k] = buffer[i][j+k+n+1] = buffer[i+n+1][j+k] = buffer[i+n+1][j+k+n+1] = buffer[i+2*n+2][j+k] = buffer[i+2*n+2][j+k+n+1] = '-';
    buffer[i+k][j] = buffer[i+k+n+1][j] = buffer[i+k][j+n+1] = buffer[i+k+n+1][j+n+1] = buffer[i+k][j+2*n+2] = buffer[i+k+n+1][j+2*n+2] = '|';
  }
}

void print(vector<vector<char> > &buffer, int N)
{
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
      cout << buffer[i][j];
    cout << '\n';
  }
}

void sub_solve(vector<vector<char> > &buffer, int i, int j, int n)
{
  draw(buffer, i+1, j+1, n);
  if (n >= 7)
  {
    sub_solve(buffer, i+2, j+2, (n-5)/2);
    sub_solve(buffer, i+n+3, j+2, (n-5)/2);
    sub_solve(buffer, i+2, j+n+3, (n-5)/2);
    sub_solve(buffer, i+n+3, j+n+3, (n-5)/2);
  }
}

void solve(int N)
{
  vector<vector<char> > buffer (N, vector<char> (N, '.'));
  sub_solve(buffer, 0, 0, (N-5)/2);
  print(buffer, N);
}

bool valid(int val)
{
  if (val == 1)
    return false;
  while (val > 5)
    if ((val-5)%2 != 0)
      return false;
    else
      val = (val-5)/2;
  return val == 1;
}

int main()
{
  int n;
  cin >> n;
  if (valid(n))
    solve(n);
  else
    cout << "GRESKA\n";
  return 0;
}
