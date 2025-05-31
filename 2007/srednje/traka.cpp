#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	freopen("traka.in", "r", stdin);
	freopen("traka.out", "w", stdout);
	scanf("%i %i", &n, &m);
	vector<int> zavise_od[n];
	int ukupno_zavisi_od[n];
	fill(ukupno_zavisi_od, ukupno_zavisi_od + n, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%i %i", &a, &b);
		zavise_od[a-1].push_back(b - 1);
		ukupno_zavisi_od[b-1]++;
	}
	bool u_rezultatu[n];
	vector<int> rezultat;
	fill(u_rezultatu, u_rezultatu + n, false);
	while (true)
	{
		int trenutni = -1;
		for (int i = 0; i < n; i++)
			if (ukupno_zavisi_od[i] == 0 && u_rezultatu[i] == false)
			{
				trenutni = i;
				break;
			}
		if (trenutni == -1)
			break;
		rezultat.push_back(trenutni);
		u_rezultatu[trenutni] = true;
		int br_komsija = zavise_od[trenutni].size();
		for (int i = 0; i < br_komsija; i++)
			ukupno_zavisi_od[zavise_od[trenutni][i]]--;
	}
	if (rezultat.size() != n)
		printf("-1");
	else
	{
		for (int i = 0; i < n - 1; i++)
			printf("%i ", rezultat[i] + 1);
		printf("%i\n", rezultat[n-1] + 1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
