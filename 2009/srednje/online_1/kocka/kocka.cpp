/// 786

#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXSUM = 80;
const int MAXDIC = 12;

int niz[MAXDIC][MAXSUM];

int limit, brojkockica;

void initialize ()
{
	memset (niz, 0, sizeof niz);

	for (int i = 1; i <= 6; i++)
		niz[1][i] = 6 - i + 1;

	for (int i = 2; i <= 11; i++)
	{
		for (int j = 1; j <= i * 6; j++)
		{
			for (int k = 1; k <= 6; k++)
			{
				niz[i][j] += niz[i - 1][max (1, j - k)];
			}
		}
	}
}

int pw (int a)
{
	int r = 1;
	for (int i = 1; i <= a; i++)
		r *= 6;
	return r;
}

int gcd (int a, int b)
{
	if (b == 0) return a;
	else return gcd (b, a % b);
}

int main (void)
{
	initialize ();

	freopen("kocka.in", "r", stdin);
	freopen("kocka.out", "w", stdout);

	int hqp; cin>>hqp;

	while (cin >> brojkockica >> limit)
	{
		if (limit == 0) {
			printf ("1\n");
			continue;
		}
		if (limit > brojkockica * 6) {
			printf ("0\n");
			continue;
		}

		int broj = niz[brojkockica][limit];
		int tot = pw (brojkockica);
		int g = gcd(broj,tot);

		if (broj==0)
			printf ("0\n");
		else if (broj==tot)
			printf ("1\n");
		else
			printf ("%d/%d\n", broj/g, tot/g);
	}

	return 0;
}


