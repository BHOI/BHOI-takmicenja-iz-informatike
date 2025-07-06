#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, t;
	
	cin >> n;

	int hist[200010] = {};
	for(int i=0;i<n;i++) {
		cin >> t;
		if(t < 0) {
			hist[-2*t]++;
		}
		else {
			hist[2*t+1]++;
		}
	}

	for(int i=0;i<200010;i++) {
		for(int j=0;j<hist[i];j++) {
			if(i % 2 == 0) {
				cout << -i/2 << " ";
			}
			else {
				cout << i/2 << " ";
			}
		}
	}

	return 0;
}
