#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

const ll INF = LLONG_MAX / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Cuvamo sve grane (u, v, w) kao listu
        vector<int> eu(2 * m), ev(2 * m);
        vector<ll> ew(2 * m);

        for (int i = 0; i < m; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            // Originalna grana: limit[v] = limit[u] + w
            eu[i] = u;
            ev[i] = v;
            ew[i] = w;
            // Obrnuta grana: limit[u] = limit[v] + (-w)
            eu[m + i] = v;
            ev[m + i] = u;
            ew[m + i] = -w;
        }

        // Bellman-Ford od cvora 1
        vector<ll> dist(n + 1, INF);
        dist[1] = 0;

        // N-1 prolaza relaksacije
        for (int iter = 0; iter < n - 1; iter++) {
            for (int i = 0; i < 2 * m; i++) {
                int u = eu[i];
                int v = ev[i];
                ll w = ew[i];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Dodatni prolaz — ako se nesto relaksira, postoji kontradikcija
        bool ok = true;
        for (int i = 0; i < 2 * m; i++) {
            int u = eu[i];
            int v = ev[i];
            ll w = ew[i];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "DA" : "NE") << "\n";
    }

    return 0;
}
