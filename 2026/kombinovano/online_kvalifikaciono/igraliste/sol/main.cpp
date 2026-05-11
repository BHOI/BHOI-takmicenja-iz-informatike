#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    bool seen[100001] = {};
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        seen[a] = true;
        seen[b] = true;
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
        if (!seen[i])
            count++;

    cout << count << "\n";
    return 0;
}
