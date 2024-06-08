#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<double> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int m;
	cin >> m;

	vector <double> a(m), b(m);

	for(int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}

	// Za svaki upit provjeravamo broj brojeva izmedju a[i] i b[i]

	// Prvo sortiramo ocjene
	sort(v.begin(), v.end());

	for(int i = 0; i < m; i++) {
		int manjiIliJednakiA, manjiOdB;
		manjiIliJednakiA = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
		manjiOdB = lower_bound(v.begin(), v.end(), b[i]) - v.begin();

		if(manjiOdB < manjiIliJednakiA)
			cout << 0 << '\n';
		else 
			cout << manjiOdB - manjiIliJednakiA << '\n';
	}

	return 0;
}