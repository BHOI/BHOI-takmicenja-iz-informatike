#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 1005;

int N, Q;
vector<int> adj[MAX_N], radj[MAX_N];
bool visited[MAX_N];
int comp[MAX_N];
stack<int> stk;

// Prvo prolazenje - punjenje steka po vremenu zavrsavanja
void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs1(v);
    stk.push(u);
}


// Drugo prolazenje - oznacavanje komponenti
void dfs2(int u, int c) {
    comp[u] = c;
    for (int v : radj[u])
        if (comp[v] == -1)
            dfs2(v, c);
}

// Kosarajuov algoritam - vraca broj SCC-ova
int kosaraju() {
    // Prvo prolazenje po originalnom grafu
    fill(visited, visited + N, false);
    while (!stk.empty()) 
        stk.pop();
    
    for (int i = 0; i < N; i++)
        if (!visited[i])
            dfs1(i);

    // Drugo prolazenje po transponovanom grafu
    fill(comp, comp + N, -1);
    int sccCount = 0;
    while (!stk.empty()) {
        int u = stk.top(); stk.pop();
    
        if (comp[u] == -1)
            dfs2(u, sccCount++);
    }

    return sccCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        // Dodaj granu u oba grafa (originalni i transponovani)
        adj[u].push_back(v);
        radj[v].push_back(u);

        // Nakon svake grane, pokreni Kosarajua od nule
        cout << kosaraju() << "\n";
    }
}