#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    vector<vector<int>> s(q, vector<int>(n)), dp(a[0], vector<int>(a[1], -1));

    dp[0][0] = 1;

    for(int i=0;i<q;i++) {
        for(int j=0;j<n;j++) {
            cin >> s[i][j];
        }
    }

    for(int i=0;i<q;i++) {
        dp[s[i][0]-1][s[i][1]-1] = 0;
    }

    // dp[i][j] ce biti jednako broju putanja koje ne prolaze kroz ni jedno stablo s

    for(int i=0;i<a[0];i++) {
        for(int j=0;j<a[1];j++) {
            if(dp[i][j] == 0) {
                // Ovdje je stablo
                continue;
            }
            if(i == 0 && j == 0) {
                continue;
            }
            dp[i][j] = 0;
            if(i > 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % 1000000007;
            }
            if(j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % 1000000007;
            }
        }
    }

    cout << dp[a[0]-1][a[1]-1] << endl;

    return 0;
}
