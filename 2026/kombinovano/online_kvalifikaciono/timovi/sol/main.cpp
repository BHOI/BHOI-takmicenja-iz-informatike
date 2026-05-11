#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 100001;

vector<int> adj[MAXN];
vector<int> radj[MAXN];
int order_arr[MAXN];
int comp[MAXN];
bool visited[MAXN];
int n, m, order_cnt;

void dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v])
        if (!visited[u])
            dfs1(u);
    order_arr[order_cnt++] = v;
}

void dfs2(int v, int c) {
    comp[v] = c;
    for (int u : radj[v])
        if (comp[u] == -1)
            dfs2(u, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    // Kosaraju-ev algoritam
    // Korak 1: DFS na originalnom grafu, zapamti redoslijed zavrsavanja
    order_cnt = 0;
    fill(visited, visited + n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i);

    // Korak 2: DFS na obrnutom grafu u obrnutom redoslijedu zavrsavanja
    fill(comp, comp + n + 1, -1);
    int num_comp = 0;
    for (int i = order_cnt - 1; i >= 0; i--) {
        int v = order_arr[i];
        if (comp[v] == -1) {
            dfs2(v, num_comp);
            num_comp++;
        }
    }

    // Izbroj velicine svake komponente
    vector<int> comp_size(num_comp, 0);
    for (int i = 1; i <= n; i++)
        comp_size[comp[i]]++;

    cout << *max_element(comp_size.begin(), comp_size.end()) << "\n";

    return 0;
}
