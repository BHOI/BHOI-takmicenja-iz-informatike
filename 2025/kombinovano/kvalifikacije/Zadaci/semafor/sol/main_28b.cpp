#include <iostream>

using namespace std;

int main() {
	int n;
	
	cin >> n;

	if(n == 10) {
		cout << "CRVENO";
	}
	else if (n < 10) {
		cout << "ZELENO";
	}

	return 0;
}
