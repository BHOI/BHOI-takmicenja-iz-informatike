#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	/*
	Za potrebe ovog rjesenja, dosta je da pretrazimo sve moguce trojke (i, j, k),
	takve da je (i < j < k), te provjerimo da li jedan od dva validna uslova vazi:
		(1) h[i] < h[j] && h[j] < h[k]
		(2) h[i] > h[j] && h[j] > h[k]
	Svaki moguci par koji ispuni taj uslov, dodajemo u `ans`.

	Mozemo i napomenuti da se u ovom rjesenju ne mora koristiti mod (1e9 + 7),
	zato sto teorijski nije moguce izgraditi toliko kombinacija u okviru N <= 250.
	*/
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if ((h[i] < h[j] and h[j] < h[k]) or (h[i] > h[j] and h[j] > h[k])) {
					ans++;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}