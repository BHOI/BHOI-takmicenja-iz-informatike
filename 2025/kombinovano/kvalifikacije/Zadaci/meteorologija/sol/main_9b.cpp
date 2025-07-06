#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int niz[4];
	for (int i = 0; i < 4; i++) {
		cin >> niz[i];
	}

	if(n == 1) {
		cout << niz[0] << endl;
		return 0;
	}

	if(n == 2) {
		if(abs(niz[0]) < abs(niz[1]) || (abs(niz[0]) == abs(niz[1]) && niz[0] < 0)) {
			cout << niz[0] << " " << niz[1] << endl;
		} else {
			cout << niz[1] << " " << niz[0] << endl;
		}
		return 0;
	}

	if(n == 3) {
		if(abs(niz[0]) > abs(niz[1]) || (abs(niz[0]) == abs(niz[1]) && niz[0] > 0)) swap(niz[0], niz[1]);
		if(abs(niz[0]) > abs(niz[2]) || (abs(niz[0]) == abs(niz[2]) && niz[0] > 0)) swap(niz[0], niz[2]);
		if(abs(niz[1]) > abs(niz[2]) || (abs(niz[1]) == abs(niz[2]) && niz[1] > 0)) swap(niz[1], niz[2]);
		cout << niz[0] << " " << niz[1] << " " << niz[2] << endl;
		return 0;
	}

	if(n == 4) {
		if(abs(niz[0]) > abs(niz[1]) || (abs(niz[0]) == abs(niz[1]) && niz[0] > 0)) swap(niz[0], niz[1]);
		if(abs(niz[0]) > abs(niz[2]) || (abs(niz[0]) == abs(niz[2]) && niz[0] > 0)) swap(niz[0], niz[2]);
		if(abs(niz[0]) > abs(niz[3]) || (abs(niz[0]) == abs(niz[3]) && niz[0] > 0)) swap(niz[0], niz[3]);
		if(abs(niz[1]) > abs(niz[2]) || (abs(niz[1]) == abs(niz[2]) && niz[1] > 0)) swap(niz[1], niz[2]);
		if(abs(niz[1]) > abs(niz[3]) || (abs(niz[1]) == abs(niz[3]) && niz[1] > 0)) swap(niz[1], niz[3]);
		if(abs(niz[2]) > abs(niz[3]) || (abs(niz[2]) == abs(niz[3]) && niz[2] > 0)) swap(niz[2], niz[3]);

		cout << niz[0] << " " << niz[1] << " " << niz[2] << " " << niz[3] << endl;
		return 0;
	}


	return 0;
}
