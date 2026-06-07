#include <iostream>
#include <vector>
#include <stack>
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

        vector<vector<pair<int, ll>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, -w));
        }

        vector<ll> val(n + 1, 0);
        vector<bool> visited(n + 1, false);
        vector<bool> in_stack(n + 1, false);

        // Rezultat: 0 = nije odluceno, 1 = DA (nadjen konzistentan ciklus), -1 = NE
        int result = 0;

        // Iterativni DFS koristeci eksplicitan stek
        // Svaki element steka: (cvor, indeks sljedeceg susjeda za obradu)
        for (int start = 1; start <= n && result == 0; start++) {
            if (visited[start]) continue;

            // Stek cuva (cvor, indeks susjeda koji ce se sljedeci obraditi)
            stack<pair<int, int>> stk;
            visited[start] = true;
            in_stack[start] = true;
            val[start] = 0;
            stk.push(make_pair(start, 0));

            while (!stk.empty() && result == 0) {
                int u = stk.top().first;
                int &idx = stk.top().second;

                if (idx < (int)adj[u].size()) {
                    int v = adj[u][idx].first;
                    ll w = adj[u][idx].second;
                    idx++;

                    if (!visited[v]) {
                        // Neposjecen cvor: posjetimo ga i dodamo na stek
                        visited[v] = true;
                        in_stack[v] = true;
                        val[v] = val[u] + w;
                        stk.push(make_pair(v, 0));
                    } else if (in_stack[v]) {
                        // Povratna grana: nasli smo ciklus
                        if (val[v] != val[u] + w) {
                            // Kontradiktorni ciklus
                            result = -1;
                        } else {
                            // Konzistentan ciklus: odmah ispisemo DA i prekidamo
                            result = 1;
                        }
                    }
                    // Ako je v posjecen ali nije in_stack, preskacemo ga
                } else {
                    // Svi susjedi cvora u su obradeni, vadimo ga sa steka
                    in_stack[u] = false;
                    stk.pop();
                }
            }
        }

        if (result == -1) {
            cout << "NE\n";
        } else {
            // result == 1 (konzistentan ciklus) ili result == 0 (nema ciklusa)
            cout << "DA\n";
        }
    }

    return 0;
}
