#include <iostream>

using namespace std;

int main() {
	int n;
	string s;
	bool nijedan = true;

	cin >> n;

	while(n--) {
		cin >> s;
		if(s[0] >= 'A' && s[0] <= 'Z') {
			cout << s[0];
			nijedan = false;
		}
	}

	if(nijedan) {
		cout << "NEMA";
	}

	return 0;
}
