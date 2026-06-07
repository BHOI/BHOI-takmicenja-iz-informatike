#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, ll>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, -w));
        }

        vector<ll> val(n + 1, 0);
        vector<bool> visited(n + 1, false);
        bool ok = true;

        for (int i = 1; i <= n && ok; i++) {
            if (visited[i]) continue;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            val[i] = 0;

            while (!q.empty() && ok) {
                int u = q.front();
                q.pop();
                for (int j = 0; j < (int)adj[u].size(); j++) {
                    int v = adj[u][j].first;
                    ll w = adj[u][j].second;
                    if (!visited[v]) {
                        val[v] = val[u] + w;
                        visited[v] = true;
                        q.push(v);
                    } else {
                        if (val[v] != val[u] + w) {
                            ok = false;
                        }
                    }
                }
            }
        }

        cout << (ok ? "DA" : "NE") << "\n";
    }

    return 0;
}
