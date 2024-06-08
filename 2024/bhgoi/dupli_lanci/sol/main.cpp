// O(N)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ok(int k, int bitmask) {
	// Ova funkcija prima "bitmask" broj u binarnom zapisu, i proverava da li se 
	// između svake dve jedinice nalazi barem "k" nula
	int copy = bitmask;
	int cnt = k;
	while(bitmask) {
		if(bitmask & 1) {
			if(cnt < k) return false;
			cnt = 0;
		} else {
			cnt++;
		}
		bitmask >>= 1;
	}

	return true;
}

int main() {
	int n, k;
	cin >> n >> k;
	
	// Koliko je lanaca dužine N takvih da između svake dvije crvene karike se nalazi barem K plavih?
	// U nastavku crvene karike su označene sa 1, a plave sa 0

	if(n <= 20) {
		// Ako je N mali, možemo proći kroz sve moguće lance i proveriti da li ispunjavaju uslov
		int ispunjavaju = 0;
		int ne_ispunjavaju = 0;
		for(int i = 0; i < (1 << n); i++) {
			if(ok(k, i)) {
				// i ispunjava uslov
				ispunjavaju++;
			} else {
				// i ne ispunjava uslov
				ne_ispunjavaju++;
			}
		}
		cout << min(ispunjavaju, ne_ispunjavaju) << endl;
		return 0;
	} else {
		// Ako je N veliki, moramo koristiti dinamičko programiranje
		long long tren; // tren je broj lanaca dužine i koji završavaju sa crvenom karikom (1), koji ispunjavaju uslov
		vector<long long> dp(k+2, 0); // dp[i] je kumulativna suma od dp[0] do dp[i], predstavlja broj 
		// validnih lanaca duzine i-1

		// Samo ćemo računati broj lanaca koji ispunjavaju uslov, jer je broj lanaca koji ne ispunjavaju uslov veći za dovoljno veliko N
		for(int i = 0; i < n; i++) {
			tren = 1; // Svi lanci 000..001 ispunjavaju uslov

			if(i - k > 0) tren += dp[(i+1)%(k+2)]; // Predstavlja dp[i-k-1], ali je indeksiranje ciklično
			tren %= 1000000007;

			dp[i%(k+2)] = tren;
			dp[i%(k+2)] += dp[(i+k+1)%(k+2)]; // Predstavlja dp[i-1], ali je indeksiranje ciklično
			dp[i%(k+2)] %= 1000000007;
		}

		long long ispunjavaju = dp[(n-1)%(k+2)];

		cout << ispunjavaju << endl;
	}

	return 0;
}
