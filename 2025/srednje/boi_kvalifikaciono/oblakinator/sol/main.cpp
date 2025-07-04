#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const long long INF = 1LL << 61;

int main() {
    int n, p, q;
    cin >> n >> p >> q;

    vector<long long> a(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    if (p + q >= n) {
        cout << 1;
        return 0;
    }

    // Binarna pretraga po rjesenju
    long long l = 0, r = INF;
    while (l + 1 < r) {
        long long w = (l + r) / 2;

        vector<vector<long long>> dp;
        dp.resize(n, vector<long long>(p + 1, 0));

        long long pointerForP = 0, pointerForQ = 0;
        for(int i = 0 ; i < n ; i++) {
            while (a[i] - a[pointerForP] >= w) pointerForP++;

            while (a[i] - a[pointerForQ] >= 2 * w) pointerForQ++;

            for(int j = 0 ; j < p + 1 ; j++) {
                if (j > 0) {
                    if (pointerForP == 0) dp[i][j] = 0;
                    else if (pointerForQ == 0) dp[i][j] = min(dp[pointerForP - 1][j - 1], 1ll);
                    else dp[i][j] = min(dp[pointerForP - 1][j - 1], dp[pointerForQ - 1][j] + 1);
                } else {
                    if (pointerForQ == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[pointerForQ - 1][j] + 1;
                }
            }
        }

        long long mn = INF;
        for(int i = 0 ; i < p + 1 ; i++) mn = min(mn, dp[n - 1][i]);

        if (mn > q) l = w;
        else r = w;
    }

    cout << r << endl;

    return 0;
}