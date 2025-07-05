/// 786

#include <string>
#include <iostream>
using namespace std;

int main (void)
{
	char sifra[130];
	string tastatura = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	for (int i = 1; i < tastatura.size (); i++)
		sifra[tastatura[i]] = tastatura[i - 1];
	sifra[' '] = ' ';

	string s;
	getline (cin, s);
	for (int i = 0; i < s.size (); i++)
		cout << sifra[s[i]];
	cout << endl;
	
	return 0;
}
