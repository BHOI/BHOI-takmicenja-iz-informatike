#include <iostream>
#include <vector>
#include <array>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	vector<vector<int>> dp(n, vector<int>(4));
	for (int i = 0; i < n; i++) {
		dp[i][1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (h[j] < h[i]) {
				dp[i][2] = ((dp[i][2] % mod) + (dp[j][1] % mod)) % mod;
				dp[i][3] = ((dp[i][3] % mod) + (dp[j][2] % mod)) % mod;
			}
		}
	} 
	vector<vector<int>> dp2(n, vector<int>(4));
	for (int i = 0; i < n; i++) {
		dp2[i][1] = 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (h[i] > h[j]) {
				dp2[i][2] = ((dp2[i][2] % mod) + (dp2[j][1] % mod)) % mod;
				dp2[i][3] = ((dp2[i][3] % mod) + (dp2[j][2] % mod)) % mod;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = ((ans % mod) + (dp[i][3] % mod)) % mod;
		ans = ((ans % mod) + (dp2[i][3] % mod)) % mod;
	}
	
	cout << ans << endl;
	return 0;
}