#include <iostream>
#include <vector>

using namespace std;

int modulo(int a, int b) {
	if(a < 0) {
		return (a % b + b) % b;
	}
	return a % b;
}

int najveci_stepen_dvojke(int n) {
	int i = 1;
	while(i <= n) {
		i *= 2;
	}
	return i / 2;
}

int main() {
	int n, t;
	cin >> n >> t;

	string s, s2(n, '0');
	char prije, poslije;

	cin >> s;

	int stepen;

	while(t > 0) {
		stepen = najveci_stepen_dvojke(t);
		for(int i = 0; i < n; i++) {
			prije = s[modulo(i - stepen, n)];
			poslije = s[modulo(i + stepen, n)];
			if(prije-'0' + poslije-'0' == 1) {
				s2[i] = '1';
			} else {
				s2[i] = '0';
			}
		}
		s = s2;
		t -= stepen;
	}

	cout << s << endl;

	return 0;
}
