#include <iostream>
using namespace std;

// Trivijalno rjesenje: uvijek ispisuje NE za svaki otok
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
        }
        cout << "NE\n";
    }
    return 0;
}
