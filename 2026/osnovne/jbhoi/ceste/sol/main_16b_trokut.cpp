#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // adj[u][v] = tezina grane u->v
        vector<map<int, ll>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            // neusmjerena grana: v.limit = u.limit + w, tj. u->v ima w, v->u ima -w
            adj[u][v] = w;
            adj[v][u] = -w;
        }

        bool ok = true;

        // Za svaku granu (u,v,w1), za svakog susjeda x od v s tezinom w2,
        // provjeri postoji li grana u->x s tezinom razlicitom od w1+w2
        for (int u = 1; u <= n && ok; u++) {
            map<int, ll>::iterator it1;
            for (it1 = adj[u].begin(); it1 != adj[u].end() && ok; ++it1) {
                int v = it1->first;
                ll w1 = it1->second;

                map<int, ll>::iterator it2;
                for (it2 = adj[v].begin(); it2 != adj[v].end() && ok; ++it2) {
                    int x = it2->first;
                    ll w2 = it2->second;

                    // Izbjegni povratak na u kroz isti put
                    if (x == u) continue;

                    // Provjeri postoji li grana u->x
                    map<int, ll>::iterator it3 = adj[u].find(x);
                    if (it3 != adj[u].end()) {
                        ll w3 = it3->second;
                        // Trokut: u->v->x i u->x, mora biti w1+w2 == w3
                        if (w1 + w2 != w3) {
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
