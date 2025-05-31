#include <string>

using namespace std;

int BakterijaSlicnost(int n, string A, string B)
{
	  int max = 0;
	  for (int i = 0; i < n; ++i)
	  {
	    A = A.substr(1, n - 1) + A[0];
	    int k = 0;
	    for (int j = 0; j < n; ++j)
	     if (A[j] == B[j]) k++;
	    if (k > max) max = k;
	  }
	  return max;
}

int BakterijaSlicnost(int n, char *A, char *B)
{
    string s1, s2;
    for (int i = 0; i < n; i++)
    {
        s1.push_back(A[i]);
        s2.push_back(B[i]);
    }
    return BakterijaSlicnost (n, s1, s2);
}
