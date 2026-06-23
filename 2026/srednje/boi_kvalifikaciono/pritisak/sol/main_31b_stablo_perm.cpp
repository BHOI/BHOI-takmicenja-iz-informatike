#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Podzadatak 6: stablo, a je permutacija
// Posto je a permutacija, za svaki cvor v postoji tacno jedan izvor u (a[u] == b[v]).
// Put u->v u stablu je jedinstven.
// Uslov: min(a) na putu u->v >= b[v] i max(b) na putu u->v <= b[v].
// Koristimo LCA sa binarnim podizanjem i sparse table za path min/max upite.
// Slozenost: O(N log N) po test-primjeru.

const int LOG = 18;

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

        // Binary lifting:
        // anc[u][k] = 2^k-ti predak cvora u
        // pathMinA[u][k] = min(a) na putu od u do anc[u][k] (ukljucivo oba kraja)
        // pathMaxB[u][k] = max(b) na putu od u do anc[u][k] (ukljucivo oba kraja)
        vector<int> depth(N + 1, 0);
        vector<vector<int>> anc(N + 1, vector<int>(LOG, 0));
        vector<vector<int>> pathMinA(N + 1, vector<int>(LOG, 0));
        vector<vector<int>> pathMaxB(N + 1, vector<int>(LOG, 0));

        // DFS iterativno da izbjegnemo stack overflow na velikim stablima
        vector<int> parent(N + 1, 0);
        vector<bool> vis(N + 1, false);
        vector<int> stk;
        stk.push_back(1);
        vis[1] = true;
        parent[1] = 0;
        vector<int> order;
        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();
            order.push_back(u);
            for (int j = 0; j < (int)adj[u].size(); j++) {
                int v = adj[u][j];
                if (!vis[v]) {
                    vis[v] = true;
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    stk.push_back(v);
                }
            }
        }

        // Inicijalizuj korijenu lifting tablicu
        anc[1][0] = 1;
        pathMinA[1][0] = a[1];
        pathMaxB[1][0] = b[1];
        for (int k = 1; k < LOG; k++) {
            anc[1][k] = 1;
            pathMinA[1][k] = a[1];
            pathMaxB[1][k] = b[1];
        }

        // Popuni tablicu za ostale cvorove u BFS redoslijedu (korijeni su prvi)
        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];
            if (u == 1) continue;
            int p = parent[u];
            anc[u][0] = p;
            pathMinA[u][0] = min(a[u], a[p]);
            pathMaxB[u][0] = max(b[u], b[p]);
            for (int k = 1; k < LOG; k++) {
                anc[u][k] = anc[anc[u][k-1]][k-1];
                pathMinA[u][k] = min(pathMinA[u][k-1], pathMinA[anc[u][k-1]][k-1]);
                pathMaxB[u][k] = max(pathMaxB[u][k-1], pathMaxB[anc[u][k-1]][k-1]);
            }
        }

        // Upit: min(a) i max(b) na putu od x do y
        auto pathQuery = [&](int x, int y) -> pair<int,int> {
            // Izjednaci dubine
            if (depth[x] < depth[y]) swap(x, y);
            int minA = a[x], maxB = b[x];
            int diff = depth[x] - depth[y];
            for (int k = 0; k < LOG; k++) {
                if (diff >> k & 1) {
                    minA = min(minA, pathMinA[x][k]);
                    maxB = max(maxB, pathMaxB[x][k]);
                    x = anc[x][k];
                }
            }
            if (x == y) return {minA, maxB};
            // Podizi oba dok im preci nisu isti
            for (int k = LOG - 1; k >= 0; k--) {
                if (anc[x][k] != anc[y][k]) {
                    minA = min(minA, min(pathMinA[x][k], pathMinA[y][k]));
                    maxB = max(maxB, max(pathMaxB[x][k], pathMaxB[y][k]));
                    x = anc[x][k];
                    y = anc[y][k];
                }
            }
            // Zadnji korak do LCA
            minA = min(minA, min(pathMinA[x][0], pathMinA[y][0]));
            maxB = max(maxB, max(pathMaxB[x][0], pathMaxB[y][0]));
            return {minA, maxB};
        };

        // Mapa: vrijednost -> cvor sa tom vrijednosti u a (permutacija)
        vector<int> srcOf(N + 1);
        for (int i = 1; i <= N; i++) srcOf[a[i]] = i;

        for (int v = 1; v <= N && ok; v++) {
            if (a[v] == b[v]) continue;
            int target = b[v];
            int u = srcOf[target];
            pair<int,int> q = pathQuery(u, v);
            if (q.first < target || q.second > target) ok = false;
        }

        cout << (ok ? 1 : 0) << "\n";
    }
    return 0;
}
