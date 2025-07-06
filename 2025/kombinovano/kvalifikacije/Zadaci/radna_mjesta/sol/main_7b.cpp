#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;

	string s, s2(n, '0');
	char prije, poslije;

	cin >> s;

	while(t--) {
		for(int i = 0; i < n; i++) {
			if(i > 0) {
				prije = s[i - 1];
			} else {
				prije = s[n - 1];
			}
			if(i < n - 1) {
				poslije = s[i + 1];
			} else {
				poslije = s[0];
			}

			if(prije-'0' + poslije-'0' == 1) {
				s2[i] = '1';
			} else {
				s2[i] = '0';
			}
		}

		s = s2;
	}

	cout << s << endl;

	return 0;
}
