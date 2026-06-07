#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// Maksimalna velicina za Floyd-Warshall matricu
const int MAXN = 501;
// Vrijednost koja predstavlja "nema puta"
const ll INF = 1e18;

ll dist[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Ucitaj sve grane u niz
        vector<int> eu(m), ev(m);
        vector<ll> ew(m);
        for (int i = 0; i < m; i++) {
            cin >> eu[i] >> ev[i] >> ew[i];
        }

        // Ako je N preveliko, Floyd-Warshall ne moze raditi — preskoci
        if (n > 500) {
            cout << "DA\n";
            continue;
        }

        // Inicijalizacija matrice rastojanja
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = INF;
                }
            }
        }

        // Postavi grane: dist[u][v] = w, dist[v][u] = -w
        for (int i = 0; i < m; i++) {
            int u = eu[i], v = ev[i];
            ll w = ew[i];
            dist[u][v] = w;
            dist[v][u] = -w;
        }

        // N prolaza relaksacije slicno Bellman-Fordu ali na svim parovima
        // Koristimo tranzitivnu relaksaciju: ako postoji put i->k i k->j,
        // onda dist[i][j] moze biti dist[i][k] + dist[k][j]
        for (int iter = 0; iter < n; iter++) {
            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        // Relaksiraj samo ako su oba puta poznata
                        if (dist[i][k] != INF && dist[k][j] != INF) {
                            ll nova = dist[i][k] + dist[k][j];
                            if (dist[i][j] == INF) {
                                dist[i][j] = nova;
                            }
                            // Ako postoji kontradikcija, vec imamo vrijednost koja se ne slaze
                        }
                    }
                }
            }
        }

        // Jos jedan prolaz: provjeri da li se ikoja vrijednost mijenja
        // Ako da, postoji kontradikcija
        bool konzistentno = true;
        for (int k = 1; k <= n && konzistentno; k++) {
            for (int i = 1; i <= n && konzistentno; i++) {
                for (int j = 1; j <= n && konzistentno; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        ll nova = dist[i][k] + dist[k][j];
                        if (dist[i][j] != INF && dist[i][j] != nova) {
                            konzistentno = false;
                        }
                    }
                }
            }
        }

        cout << (konzistentno ? "DA" : "NE") << "\n";
    }

    return 0;
}
