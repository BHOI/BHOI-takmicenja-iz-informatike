#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		int b;
		string s;
		
		cin >> b >> s;

		int x = 0;
		int trenutna_cifra = 0;
		for(int i=0; i<s.size(); i++){
			if(s[i] >= 'A' && s[i] <= 'Z') {
				trenutna_cifra = s[i] - 'A' + 10;
			} else {
				trenutna_cifra = s[i] - '0';
			}

			x *= b;
			x += trenutna_cifra;
		}

		if(x % (b-1) == 0) {
			cout << "DA" << endl;
		} else {
			cout << "NE" << endl;
		}
	}

	return 0;
}