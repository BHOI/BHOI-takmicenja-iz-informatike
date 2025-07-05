/// 786

#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int prosti[5000], ps;

void init ()
{
	const int sz = 46500;
	bool niz[sz];
	memset (niz, 1, sizeof niz);
	for (int i = 2; i < sz; i++) for (int j = 2 * i; j < sz; j += i)
		niz[j] = false;

	ps = 0;
	for (int i = 2; i < sz; i++) if (niz[i]) prosti[ps++] = i;
}

bool solve (int a, int b) // b | a! ?
{
	int limit = sqrt (double (b)), 
		tmp = b, 
		num;
	
	for (int i = 0; prosti[i] <= limit && b > 1; i++) {
		if (prosti[i] > a) return false;
		num = 0;
		while (b % prosti[i] == 0 && ++num) b /= prosti[i];
		if (a / prosti[i] < num) return false;
	}
	if (b > a) return false;
	return true;
}

int main (void)
{
	init ();
	int t, a, b;
	cin >> t;
	while (t-- && cin >> a >> b)
		cout << (solve (a, b) ? "Hura" : "Ouch") << endl;
	return 0;
}
