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

	for(int i = 0; i < m; i++) {
		int br = 0;
		for(int j = 0; j < n; j++) {
			if(v[j] > a[i] && v[j] < b[i]) {
				br++;
			}
		}
		cout << br << '\n';
	}

	return 0;
}