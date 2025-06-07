#include <iostream>

using namespace std;

int dec(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;
	else
		return c - 'A' + 10;
}

int main()
{
	int n;
	string k;
	cin >> n >> k;
	unsigned k_dec = 0;
	for (string::const_iterator i = k.begin(); i != k.end(); ++i)
		(k_dec *= n) += dec(*i);
	cout << k_dec << endl;
	return 0;
}
