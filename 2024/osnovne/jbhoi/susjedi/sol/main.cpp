#include <iostream>

using namespace std;

long long niz[100000];

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> niz[i];
	}

	long long prvi = 1, zbir = niz[0] + niz[1];

	for(int i = 0; i < n - 1; i++) {
		if(niz[i] + niz[i + 1] >= zbir) {
			zbir = niz[i] + niz[i + 1];
			prvi = i + 1;
		}
	}

	cout << prvi << " " << prvi + 1 << " " << zbir << endl;

	return 0;
}