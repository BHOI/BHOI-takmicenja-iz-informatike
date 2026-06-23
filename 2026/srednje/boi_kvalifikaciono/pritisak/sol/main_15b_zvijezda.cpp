#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200009;
int a[MAXN], b[MAXN];
vector<int> adj[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; i++) cin >> a[i];
        for (int i = 1; i <= N; i++) cin >> b[i];
        for (int i = 1; i <= N; i++) adj[i].clear();
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

        // Provjera: svaka vrijednost u b mora postojati u a
        bool inA[MAXN];
        for (int i = 1; i <= N; i++) inA[i] = false;
        for (int i = 1; i <= N; i++) inA[a[i]] = true;
        for (int i = 1; i <= N; i++) {
            if (!inA[b[i]]) { ok = false; break; }
        }
        if (!ok) { cout << "0\n"; continue; }

        // Nadi korijen zvijezde (cvor stepena N-1)
        int root = -1;
        for (int i = 1; i <= N; i++) {
            if ((int)adj[i].size() == N - 1) { root = i; break; }
        }

        // Za svaki list v, provjeri da moze biti zadovoljen
        // Mogucnosti:
        // 1. b[v] == a[v]: vec zadovoljeno
        // 2. b[v] == a[root]: direktno iz korijena (put: root -> v)
        // 3. postoji list u sa a[u] == b[v]: put ide kroz korijen (u -> root -> v),
        //    sto je moguce ako a[root] >= b[v] i b[root] <= b[v]
        for (int i = 0; i < (int)adj[root].size() && ok; i++) {
            int v = adj[root][i];
            if (b[v] == a[v]) continue;
            if (b[v] == a[root]) continue;
            if (a[root] >= b[v] && b[root] <= b[v]) continue;
            ok = false;
        }

        // Provjeri i korijen sam
        if (ok && b[root] != a[root]) {
            // Korijen mora dobiti pritisak b[root] od nekog lista u sa a[u] == b[root]
            // Put ide: u -> root, sto zahtijeva b[u] <= b[root]
            bool found = false;
            for (int i = 0; i < (int)adj[root].size() && !found; i++) {
                int u = adj[root][i];
                if (a[u] == b[root] && b[u] <= b[root]) found = true;
            }
            if (!found) ok = false;
        }

        cout << (ok ? 1 : 0) << "\n";
    }
    return 0;
}
