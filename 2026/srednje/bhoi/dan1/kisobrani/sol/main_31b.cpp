#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Umbrella {
    int a, b;
};

int R, C, N, Q;
vector<Umbrella> umbrellas[101];

int simulate(int col) {
    for (int row = 1; row <= R; row++) {
        for (int j = 0; j < (int)umbrellas[row].size(); j++) {
            int a = umbrellas[row][j].a;
            int b = umbrellas[row][j].b;
            if (a > col) break;
            if (col >= a && col <= b) {
                int w = b - a + 1;
                if (col < a + w / 2) {
                    col = a - 1;
                } else {
                    col = b + 1;
                }
                break;
            }
        }
    }
    return col;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> N >> Q;

    for (int i = 0; i < N; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        umbrellas[r].push_back({a, b});
    }

    for (int row = 1; row <= R; row++) {
        sort(umbrellas[row].begin(), umbrellas[row].end(),
             [](const Umbrella &x, const Umbrella &y) { return x.a < y.a; });
    }

    // Brute force: simuliraj svaku kap, prefix sume
    vector<int> landing(C + 2, 0);
    for (int c = 1; c <= C; c++) {
        int dest = simulate(c);
        if (dest >= 1 && dest <= C) {
            landing[dest]++;
        }
    }

    vector<ll> prefix(C + 2, 0);
    for (int i = 1; i <= C; i++) {
        prefix[i] = prefix[i - 1] + landing[i];
    }

    for (int q = 0; q < Q; q++) {
        int L, D;
        cin >> L >> D;
        cout << prefix[D] - prefix[L - 1] << "\n";
    }

    return 0;
}
