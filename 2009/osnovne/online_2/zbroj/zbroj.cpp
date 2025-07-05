#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   int n;
   int rj = 0;
   cin >> n;
   for ( int i=0; i<n; ++i ) {
	  string s;
	  cin >> s;
	  sort( s.begin(), s.end(), greater<char>() );
	  rj += atoi( s.c_str() );
   }
   cout << rj << endl;
   return 0;
}
