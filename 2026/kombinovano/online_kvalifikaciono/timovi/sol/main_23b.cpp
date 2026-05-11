#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1), radj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    // O(N^2) pristup: za svaki cvor, BFS naprijed i nazad
    // Presjek dostupnih skupova iz v (naprijed) i do v (nazad)
    // daje SCC koja sadrzi v

    int best = 1;

    for (int v = 1; v <= n; v++) {
        // BFS naprijed iz v
        vector<bool> fwd(n + 1, false);
        queue<int> q;
        q.push(v);
        fwd[v] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int w : adj[u])
                if (!fwd[w]) { fwd[w] = true; q.push(w); }
        }

        // BFS nazad iz v (na obrnutom grafu)
        vector<bool> bwd(n + 1, false);
        q.push(v);
        bwd[v] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int w : radj[u])
                if (!bwd[w]) { bwd[w] = true; q.push(w); }
        }

        // Prebroj presjek
        int cnt = 0;
        for (int u = 1; u <= n; u++)
            if (fwd[u] && bwd[u])
                cnt++;

        best = max(best, cnt);
    }

    cout << best << "\n";
    return 0;
}
