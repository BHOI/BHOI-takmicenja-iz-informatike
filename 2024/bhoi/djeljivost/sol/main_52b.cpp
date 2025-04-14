#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		int b;
		string s;
		
		cin >> b >> s;
		
		// Konvertovati u bazu 10
		int x = 0, cifra;
		for(int i=s.size()-1; i>=0; i--){
			x *= b;
			cifra = s[i] - '0';
			x += cifra;
		}
		
		if(x % (b-1) == 0) {
			cout << "DA" << endl;
		} else {
			cout << "NE" << endl;
		}
	}

	return 0;
}