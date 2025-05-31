#include <fstream>
using namespace std;
const unsigned short int maxN = 100;

int main()
{
 unsigned short int n, xn[maxN];
 unsigned short int nZnam, j, d, dj;

 ifstream ulaz("nx.in");
 ulaz >> n;
 d=0;  nZnam=0;  j=n;

 do {
   nZnam++;
   xn[nZnam]=j;
   dj = xn[nZnam]*n + d;
   j = dj % 10;
   d = dj / 10;
 } while ((j != n) || (d != 0));

 ofstream izlaz("nx.out");
 for (int i = nZnam; i >= 1; i--)
   izlaz << xn[i];
 izlaz << endl; 
 return 0;
}
