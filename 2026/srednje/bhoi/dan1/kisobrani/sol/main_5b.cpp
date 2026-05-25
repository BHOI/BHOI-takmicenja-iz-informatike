#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, N, Q;
    cin >> R >> C >> N >> Q;

    for (int i = 0; i < N; i++) {
        int r, a, b;
        cin >> r >> a >> b;
    }

    for (int q = 0; q < Q; q++) {
        int L, D;
        cin >> L >> D;
        cout << D - L + 1 << "\n";
    }

    return 0;
}
