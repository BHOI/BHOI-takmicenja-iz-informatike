/// 786

#include <cstdio>
#include <iostream>
using namespace std;

int main (void) 
{
	FILE *fx = freopen ("tvrtko.in",  "r", stdin);
	FILE *fy = freopen ("tvrtko.out", "w", stdout);

	int a, b;
	cin >> a >> b;

	int rez = (a < b ? b - a : a - b); 
	cout << rez << endl;

	return 0;
}

