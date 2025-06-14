#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		int b;
		int s;
		
		cin >> b >> s;
		if(s == b-1) {
			cout << "DA" << endl;
		} else {
			cout << "NE" << endl;
		}
		
	}

	return 0;
}