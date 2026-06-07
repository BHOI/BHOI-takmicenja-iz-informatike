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

        // adj[u] sadrzi parove (v, w) gdje je w tezina grane u->v
        vector<vector<pair<int, ll>>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, -w));
        }

        bool ok = true;

        // Provjera samo ciklusa duzine 3 i 4 (trokuti i cetvorougaonici)
        // Ciklus duzine 3: a->b->c->a
        // Ciklus duzine 4: a->b->c->d->a

        // Gradimo mapu susjednosti za brzu provjeru grana
        vector<map<int, ll>> adjmap(n + 1);
        for (int u = 1; u <= n; u++) {
            for (int j = 0; j < (int)adj[u].size(); j++) {
                int v = adj[u][j].first;
                ll w = adj[u][j].second;
                adjmap[u][v] = w;
            }
        }

        // Provjera trokuta: ciklus duzine 3
        // Za svaku granu (a,b,w1), za svakog susjeda c od b (c != a),
        // provjeri postoji li grana c->a i da li je suma konzistentna
        for (int a = 1; a <= n && ok; a++) {
            for (int j = 0; j < (int)adj[a].size() && ok; j++) {
                int b = adj[a][j].first;
                ll w1 = adj[a][j].second;

                for (int k = 0; k < (int)adj[b].size() && ok; k++) {
                    int c = adj[b][k].first;
                    ll w2 = adj[b][k].second;

                    if (c == a) continue;

                    // Provjeri granu c->a
                    map<int, ll>::iterator it = adjmap[c].find(a);
                    if (it != adjmap[c].end()) {
                        ll w3 = it->second;
                        // Ciklus a->b->c->a: w1 + w2 + w3 mora biti 0
                        if (w1 + w2 + w3 != 0) {
                            ok = false;
                        }
                    }
                }
            }
        }

        // Provjera cetvorougaonika: ciklus duzine 4
        // Za svaku granu (a,b,w1), za svakog susjeda c od b (c != a),
        // za svakog susjeda d od c (d != b, d != a),
        // provjeri postoji li grana d->a i da li je suma konzistentna
        for (int a = 1; a <= n && ok; a++) {
            for (int j = 0; j < (int)adj[a].size() && ok; j++) {
                int b = adj[a][j].first;
                ll w1 = adj[a][j].second;

                for (int k = 0; k < (int)adj[b].size() && ok; k++) {
                    int c = adj[b][k].first;
                    ll w2 = adj[b][k].second;

                    if (c == a) continue;

                    for (int l = 0; l < (int)adj[c].size() && ok; l++) {
                        int d = adj[c][l].first;
                        ll w3 = adj[c][l].second;

                        if (d == b || d == a) continue;

                        // Provjeri granu d->a
                        map<int, ll>::iterator it = adjmap[d].find(a);
                        if (it != adjmap[d].end()) {
                            ll w4 = it->second;
                            // Ciklus a->b->c->d->a: w1 + w2 + w3 + w4 mora biti 0
                            if (w1 + w2 + w3 + w4 != 0) {
                                ok = false;
                            }
                        }
                    }
                }
            }
        }

        cout << (ok ? "DA" : "NE") << "\n";
    }

    return 0;
}
