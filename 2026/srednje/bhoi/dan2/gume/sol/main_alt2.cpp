#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(2, vector<int>(2 * n));
    map<int, vector<pair<int, int>>> positions;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cin >> g[i][j];
            positions[g[i][j]].push_back({i, j});
        }
    }

    int tr[4] = {0, 0, 1, 1};
    int tc[4] = {0, 1, 0, 1};

    int ans = 1<<29;

    for (auto it = positions.begin(); it != positions.end(); ++it) {
        vector<pair<int, int>> &pos = it->second;
        int k = (int)pos.size();
        if (k < 4) continue;

        vector<int> dp(16, 1<<29);
        dp[0] = 0;

        for (int i = 0; i < k; i++) {
            int r = pos[i].first;
            int c = pos[i].second;

            for (int mask = 14; mask >= 0; mask--) {
                if (dp[mask] == 1<<29) continue;
                for (int j = 0; j < 4; j++) {
                    if (mask & (1 << j)) continue;
                    int cost = abs(r - tr[j]) + abs(c - tc[j]);
                    int new_mask = mask | (1 << j);
                    dp[new_mask] = min(dp[new_mask], dp[mask] + cost);
                }
            }
        }

        if (dp[15] < ans) {
            ans = dp[15];
        }
    }

    cout << ans << "\n";

    return 0;
}
