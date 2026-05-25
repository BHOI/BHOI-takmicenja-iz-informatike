// naivno bubble sort rješenje
#include <bits/stdc++.h>
using namespace std;

using Gate = pair<int, int>;
using Network = vector<Gate>;

static Network bubbleNetwork(int n) {
    Network net;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; --j) {
            net.emplace_back(j - 1, j);
        }
    }
    return net;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        Network net = bubbleNetwork(n);
        cout << net.size() << '\n';
        for (auto [a, b] : net) {
            cout << a << ' ' << b << '\n';
        }
    }
}
