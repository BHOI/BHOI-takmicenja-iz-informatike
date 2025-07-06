#include <iostream>

using namespace std;

int main() {
	bool ijedan = false;
	int n;
	string s;
	
	cin >> n;

	cin >> s;
	if(s[0] >= 'A' && s[0] <= 'Z') {
		cout << s[0];
		ijedan = true;
	}
	cin >> s;
	if(s[0] >= 'A' && s[0] <= 'Z') {
		cout << s[0];
		ijedan = true;
	}
	cin >> s;
	if(s[0] >= 'A' && s[0] <= 'Z') {
		cout << s[0];
		ijedan = true;
	}

	if(!ijedan) {
		cout << "NEMA";
	}

	return 0;
}
