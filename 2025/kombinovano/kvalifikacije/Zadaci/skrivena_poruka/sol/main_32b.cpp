#include <iostream>

using namespace std;

int main() {
	int n;
	string s;
	
	cin >> n;

	while(true) {
		cin >> s;
		if(s[0] >= 'A' && s[0] <= 'Z') {
			cout << s[0];
			return 0;
		}
	}
}
