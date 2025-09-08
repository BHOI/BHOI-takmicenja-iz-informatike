#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	map<int, map<int, int>> mp; // Za svako moguce V_j imamo odvojenu mapu
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		for (int v = 1; v < 100000000; v *= 2) {
			// Za svako potencijalno V_j povecamo brojac
			mp[v][t%v]++;
		}
	}
	int v, p;
	for(int i=0;i<q;i++) {
		cin >> v >> p;
		if(p == v) p = 0;
		cout << mp[v][p] << ' ';
	}

	cout << endl;

	return 0;
}