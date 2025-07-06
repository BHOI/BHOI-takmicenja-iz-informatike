#include <iostream>

using namespace std;

int main() {
	int n, t;
	
	cin >> n;

	bool hist[100010] = {};
	for(int i=0;i<n;i++) {
		cin >> t;
		hist[t] = true;
	}

	for(int i=0;i<100010;i++) {
		if(hist[i]) {
			cout << i << " ";
		}
	}

	return 0;
}
