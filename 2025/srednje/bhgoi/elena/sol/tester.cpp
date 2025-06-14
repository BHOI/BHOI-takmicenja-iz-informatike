#include <iostream>
#include <vector>


#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
using namespace std;

int rev(int n) {
    if(n == -1) return 1;
    if(n == 1) return -1;
    return 0;
}

signed main() {
	int n, m, cnt, x, y;
	string temp;
	cin >> n >> m >> cnt;
	vector<vector<vector<int>>> dp(cnt + 1, vector<vector<int>>(n, vector<int>(m)));
	vector<pii> dirs;
	for(int i = 0; i < 3; i++) {
		cin >> temp;
		for(int j = 0; j < 3; j++) {
			if(temp[j] == '*') dirs.push_back({rev(i - 1), rev(j - 1)});
		}
	}
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		cin >> temp;
		for(int j = 0; j < m; j++) {
			a[i][j] = (temp[j] == '#');
			if(temp[j] == 'C') {
				x = i, y = j;
			}
		}
	}
	dp[0][x][y] = 1;
	pii pe;
	vector<vector<int>> ans(n, vector<int>(m));
    int res = 0, mx = 0, my = 0;
	for(int k = 0; k <= cnt; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
                ans[i][j] = (ans[i][j] + dp[k][i][j]) % 1000000007;
                if(ans[i][j] > res) {
                    res = ans[i][j], mx = i, my = j;
                }
				if(k == cnt || !dp[k][i][j]) continue;
				for(auto d : dirs) {
					pe = {i + d.ff, j + d.ss};
					if(0 <= pe.ff && pe.ff < n && 0 <= pe.ss && pe.ss < m && !a[pe.ff][pe.ss]) {
					    dp[k + 1][pe.ff][pe.ss] = (dp[k + 1][pe.ff][pe.ss] + dp[k][i][j]) % 1000000007;
					}
				}
			}
		}
	}
	cout << mx + 1 << " " << my + 1 << "\n" << res << "\n";
}