#include <iostream>

using namespace std;

int main() {
	int n;
	
	cin >> n;

	if((n/10)%2 == 0) {
		cout << "ZELENO";
	} else {
		cout << "CRVENO";
	}

	return 0;
}
