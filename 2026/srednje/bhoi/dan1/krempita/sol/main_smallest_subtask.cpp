#include <bits/stdc++.h>
using namespace std;

using Gate = pair<int, int>;
using Network = vector<Gate>;

static Network manualNetwork(int n) {
    if (n == 2) {
        return {{0, 1}};
    }
    if (n == 3) {
        return {{0, 2}, {0, 1}, {1, 2}};
    }
    if (n == 4) {
        return {{0, 2}, {1, 3}, {0, 1}, {2, 3}, {1, 2}};
    }
    if (n == 5) {
        return {
            {0, 3}, {1, 4}, {0, 2}, {1, 3}, {0, 1},
            {2, 4}, {1, 2}, {3, 4}, {2, 3}
        };
    }
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        Network net = manualNetwork(n);
        cout << net.size() << '\n';
        for (auto [a, b] : net) {
            cout << a << ' ' << b << '\n';
        }
    }
}
