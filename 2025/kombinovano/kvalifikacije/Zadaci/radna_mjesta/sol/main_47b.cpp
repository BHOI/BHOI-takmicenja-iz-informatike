#include <iostream>
#include <vector>

using namespace std;

long long modulo(long long a, long long b) {
	if(a < 0) {
		return (a % b + b) % b;
	}
	return a % b;
}

int main() {
	long long n, t;
	cin >> n >> t;

	string s, s2(n, '0');
	char prije, poslije;

	cin >> s;

	// Simuliramo dvana40 koraka tako što s[i] samo ovisi od s[i-dvana40] i s[i+dvana40] (kao da su direktni susjedi)
	long long dvana40 = 1<<20;
	dvana40 *= dvana40;

	while(t > dvana40) {
		for(int i = 0; i < n; i++) {
			prije = s[modulo(i - dvana40, n)];
			poslije = s[modulo(i + dvana40, n)];
			if(prije-'0' + poslije-'0' == 1) {
				s2[i] = '1';
			} else {
				s2[i] = '0';
			}
		}
		s = s2;
		t -= dvana40;
	}

	// Simuliramo dvana20 koraka tako što s[i] samo ovisi od s[i-dvana20] i s[i+dvana20] (kao da su direktni susjedi)
	int dvana20 = 1<<20;

	while(t > dvana20) {
		for(int i = 0; i < n; i++) {
			prije = s[modulo(i - dvana20, n)];
			poslije = s[modulo(i + dvana20, n)];
			if(prije-'0' + poslije-'0' == 1) {
				s2[i] = '1';
			} else {
				s2[i] = '0';
			}
		}
		s = s2;
		t -= dvana20;
	}

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
