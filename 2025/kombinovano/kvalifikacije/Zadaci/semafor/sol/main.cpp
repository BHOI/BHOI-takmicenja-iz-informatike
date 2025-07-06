#include <iostream>

using namespace std;

int main() {
	long long n;
	
	cin >> n;

	if((n/10)%2 == 0) {
		cout << "ZELENO" << endl;
	} else {
		cout << "CRVENO" << endl;
	}

	return 0;
}
