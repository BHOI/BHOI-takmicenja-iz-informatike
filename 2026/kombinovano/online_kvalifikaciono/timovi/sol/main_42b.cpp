#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Podzadatak 3: N=M, svaki cvor ima ulazni i izlazni stepen 1
    // Graf je unija disjunktnih ciklusa
    // Pronadji najduzi ciklus

    vector<int> next_node(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        next_node[a] = b;
    }

    vector<bool> visited(n + 1, false);
    int best = 1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int len = 0;
            int cur = i;
            while (!visited[cur]) {
                visited[cur] = true;
                cur = next_node[cur];
                len++;
            }
            best = max(best, len);
        }
    }

    cout << best << "\n";
    return 0;
}
