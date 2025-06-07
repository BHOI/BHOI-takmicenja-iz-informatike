#include <iostream>
#include <cstring>
using namespace std;

int myabs(int a)
{
	if (a < 0)
		return -a;
	else
		return a;
}

int main(void)
{
	char broja[10001], brojb[10001];
	cin >> broja >> brojb;
	int cifre_broja[10], cifre_brojb[10];
	for (int i = 0; i < 10; i++)
		cifre_broja[i] = cifre_brojb[i] = 0;
	int len = strlen(broja);
	for (int i = 0; i < len; i++)
	{
		cifre_broja[broja[i]-'0']++;
		cifre_brojb[brojb[i]-'0']++;
	}
	int rezultat = 0;
	for (int i = 0; i < 10; i++)
		rezultat += myabs(cifre_broja[i] - cifre_brojb[i]);
	cout << rezultat/2 << endl;
	return 0;
}


