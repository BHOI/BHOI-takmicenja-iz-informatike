#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

const int MAX_N = 1e4 + 5;

int N, Q;
vector<int> adj[MAX_N];
int par[MAX_N], rnk[MAX_N];
int sccCount;

// Pronadji root komponente
int find(int x) {
    while (par[x] != x) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

// Spajanje komponenti
void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
    sccCount--;
}

// BFS po originalnom grafu od cvora src, vraca skup svih dostupnih cvorova
unordered_set<int> bfs(int src) {
    unordered_set<int> visited;
    queue<int> q;
    q.push(src);
    visited.insert(src);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int nb : adj[curr]) {
            if (!visited.count(nb)) {
                visited.insert(nb);
                q.push(nb);
            }
        }
    }
    return visited;
}

void query(int u, int v) {
    // Dodaj granu u originalni graf
    adj[u].push_back(v);

    // Ako su vec u istom SCC-u, nema promjene
    if (find(u) == find(v)) {
        cout << sccCount << "\n";
        return;
    }

    // Provjeravamo da li v moze da dostigne u.
    // Ako da, nova grana u -> v zatvara ciklus, i svi cvorovi
    // na tom putu postaju jedan SCC.
    unordered_set<int> reachable = bfs(v);

    // Nema ciklusa, nema promjene u broju SCC-ova
    if (!reachable.count(u)) {
        cout << sccCount << "\n";
        return;
    }

    // Ciklus postoji -- spoji sve cvorove dostupne iz v
    // koji mogu da dostignu u (tj. koji su na ciklusu).
    // Konzervativna aproksimacija: spajamo sve cvorove
    // dostupne iz v ciji SCC moze da dostigne SCC od u.
    // 
    // Jednostavnosti radi: spajamo sve cvorove iz reachable
    // koji su na putu v -> ... -> u, sto je podskup reachable.
    // Dovoljno je spojiti sve cvorove dostupne iz v sa u,
    // jer su svi oni dio istog ciklusa kroz u -> v -> ... -> u.
    for (int node : reachable) {
        // Provjeri da li ovaj cvor moze da dostigne u
        // (tj. da li je zaista na ciklusu)
        unordered_set<int> fwd = bfs(node);
        if (fwd.count(u)) {
            merge(u, node);
        }
    }

    cout << sccCount << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    sccCount = N;
    for (int i = 0; i < N; i++) {
        par[i] = i;
        rnk[i] = 0;
    }

    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        query(u, v);
    }
}