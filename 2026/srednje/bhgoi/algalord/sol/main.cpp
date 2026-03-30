#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

const int MAX_N = 1e5 + 5;

int par[MAX_N], rnk[MAX_N];
vector<int> adj[MAX_N];   // kondenzovani DAG: grane naprijed
vector<int> radj[MAX_N];  // kondenzovani DAG: grane unazad
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
    // a i b su vec reprezentanti svojih SCC-ova
    // Prioritizuje se komponenta koja je veceg ranga,
    // kako bi stablo DSU-a ostalo sto plice
    if (rnk[a] < rnk[b])
        swap(a, b);

    par[b] = a; // b visi ispod a

    // Rang se povecava samo kada su rangovi jednaki,
    // jer tada stablo postaje za jedan nivo dublje
    if (rnk[a] == rnk[b])
        rnk[a]++;

    // Preusmjeravamo grane SCC-a b na novi reprezentant a,
    // kako bi kondenzovani DAG ostao konzistentan
    for (int nb : adj[b])
        adj[a].push_back(nb);
    adj[b].clear();

    for (int nb : radj[b])
        radj[a].push_back(nb);
    radj[b].clear();

    sccCount--;
}

// BFS po grafu g od cvora src; vraca skup dostupnih SCC reprezentanata
unordered_set<int> bfs(int src, vector<int> g[]) {
    unordered_set<int> seen;
    queue<int> q;
    seen.insert(src);
    q.push(src);
    while (!q.empty()) {
        int curr = find(q.front()); q.pop();
        for (int nb : g[curr]) {
            nb = find(nb);
            if (!seen.count(nb)) {
                seen.insert(nb);
                q.push(nb);
            }
        }
    }
    return seen;
}

void query(int u, int v) {
    // Pronadji SCC cvorova u i v
	u = find(u);
	v = find(v);
    if (u == v) { // Ako su jednaki, nema promjena u broju SCC-ova
		cout << sccCount << "\n";
		return;
	}

	// Dodaj granu u oba smjera kondenzovanog DAG-a
    adj[u].push_back(v);
    radj[v].push_back(u);

	/*
		Provjeravamo da li nova grana u->v zatvara ciklus.
		Ciklus postoji ako v moze da dostigne u (po starim granama).

		Ispravna skup cvorova za spajanje je presjek:
		  - cvorovi dostupni iz v (idemo naprijed od v)
		  - cvorovi koji mogu doci do u (idemo unazad od u)
		Samo cvorovi u oba skupa su zaista na ciklusu sa u.
	*/
    auto fwd = bfs(v, adj);

	// Nema promjene u broju SCC-ova ako nije pronadjen put v -> u
    if (!fwd.count(u)) {
		cout << sccCount << "\n";
		return;
	}

	// Unazad BFS od u: cvorovi koji mogu dostici u
    auto rev = bfs(u, radj);

    // Spoji samo cvorove koji su i dostupni iz v I mogu dostici u
    int rep = find(u);
    for (int x : fwd) {
        x = find(x);
        if (rev.count(x) && x != find(rep)) {
            merge(find(rep), x);
            rep = find(rep);
        }
    }

    cout << sccCount << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	// Unos broja cvorova i broja upita
    int N, Q;
    cin >> N >> Q;

	// Na pocetku, graf nema ni jednu granu, tako da je broj SCC-ova
	// jednak broju cvorova (jedan cvor je po definiciji SCC-a i dalje SCC).
	// Takodje postavlja se rang = 0, jer su u pocetku svi SCC-ovi iste vaznosti.
    sccCount = N;
    for (int i = 0; i < N; i++) {
		par[i] = i, rnk[i] = 0;
	}

	// Procesuiranje upita -- dodavanje grane, eventualno spajanje komponenti
	// i ispis rezultata
    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        query(u, v);
    }
}