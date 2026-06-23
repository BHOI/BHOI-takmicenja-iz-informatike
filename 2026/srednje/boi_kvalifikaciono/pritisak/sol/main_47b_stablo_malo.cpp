#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Podzadatak 5: stablo, suma N^2 <= 5,000,000
// Za svaki cvor v pokrecemo BFS od svih izvora sa a[u] == b[v],
// prolazeci kroz cvorove w sa a[w] >= b[v] i b[w] <= b[v].
// Slozenost: O(N * (N + M)) po test-primjeru, tj. O(N^2) za stabla.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> a(N + 1), b(N + 1);
        for (int i = 1; i <= N; i++) cin >> a[i];
        for (int i = 1; i <= N; i++) cin >> b[i];

        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Provjera: b[u] <= a[u] za sve cvorove
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            if (b[i] > a[i]) { ok = false; break; }
        }
        if (!ok) { cout << "0\n"; continue; }

        // Za svaki cvor v: BFS od svih u sa a[u] == b[v]
        vector<bool> vis(N + 1);
        for (int v = 1; v <= N && ok; v++) {
            if (a[v] == b[v]) continue;
            int target = b[v];

            for (int i = 1; i <= N; i++) vis[i] = false;
            queue<int> q;
            for (int u = 1; u <= N; u++) {
                if (a[u] == target && b[u] <= target) {
                    vis[u] = true;
                    q.push(u);
                }
            }

            bool found = vis[v];
            while (!q.empty() && !found) {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < (int)adj[cur].size(); j++) {
                    int nxt = adj[cur][j];
                    if (!vis[nxt] && a[nxt] >= target && b[nxt] <= target) {
                        vis[nxt] = true;
                        if (nxt == v) { found = true; break; }
                        q.push(nxt);
                    }
                }
            }

            if (!found) ok = false;
        }

        cout << (ok ? 1 : 0) << "\n";
    }
    return 0;
}
