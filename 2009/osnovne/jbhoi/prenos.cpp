/// JBHOI 2009
/// Zadatak: prenos

#include <iostream>
using namespace std;

int main (void)
{
	int a, b;
	cin >> a >> b;
	
	int res = 0;
	
	int prenos = 0;
	while (a || b)
	{
		int t = (a % 10) + (b % 10) + prenos;
		if (t > 9) 
		{
			res++;
			prenos = t / 10;
		}
		else prenos = 0;
		
		a /= 10; 
		b /= 10;
	}
	
	cout << res << endl;
	return 0;
}
