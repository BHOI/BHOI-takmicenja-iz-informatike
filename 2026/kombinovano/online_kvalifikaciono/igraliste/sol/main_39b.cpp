#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Matrica vidljivosti: adj[i][j] = 1 ako se dijete i i dijete j vide
    int adj[11][11] = {};
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    // Dijete ne moze saznati broj ako je cijeli red nula (niko ga ne vidi)
    int count = 0;
    for (int i = 1; i <= n; i++) {
        bool has_neighbor = false;
        for (int j = 1; j <= n; j++) {
            if (adj[i][j]) {
                has_neighbor = true;
                break;
            }
        }
        if (!has_neighbor) count++;
    }

    cout << count << "\n";
    return 0;
}
