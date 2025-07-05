/// 786

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 55;

bool trazi (int pocetni, int *brojevi, int nbroj, int *rezultat)
{
	bool zabranjen[MAX];
	memset (zabranjen, 0, sizeof zabranjen);

	int nrez = 0;
	rezultat[nrez++] = pocetni;

	int velicina = nbroj;
	while (velicina > 0)
	{
		int najmanji;
		for (int i = 0; i < nbroj; i++)
			if (!zabranjen[i])
			{
				najmanji = brojevi[i];
				break;
			}

		for (int i = 0; i < nrez; i++)
		{
			bool nasao = false;
			for (int j = 0; j < nbroj; j++) if (!zabranjen[j] && brojevi[j] == najmanji - pocetni + rezultat[i])
			{
				zabranjen[j] = true;
				nasao = true;
				velicina--;
				break;
			}
			if (!nasao) return false;
		}

		rezultat[nrez++] = najmanji - pocetni;
	}

	return true;
}

int main (void)
{
freopen("sume.in","r",stdin);
freopen("sume.out","w",stdout);
	int nta, n, brojevi[MAX], rezultat[20];
	scanf ("%d", &nta);

	while (nta--)
	{
		scanf ("%d", &n);
		int nbroj = (n * n - n) / 2;
		for (int i = 0; i < nbroj; i++)
			scanf ("%d", &brojevi[i]);

		sort (brojevi, brojevi + nbroj);

		bool pronasao = false;
		for (int i = (brojevi[0] - brojevi[nbroj - 1]); i < abs (brojevi[0]); i++)
		{
			if (pronasao = trazi (i, brojevi, nbroj, rezultat))
				break;
		}

		if (!pronasao) 
			printf ("Nemoguca misija\n");
		else for (int i = 0; i < n; i++) 
			printf ("%d%s", rezultat[i], (i != n - 1 ? " " : "\n"));
	}

	return 0;
}
