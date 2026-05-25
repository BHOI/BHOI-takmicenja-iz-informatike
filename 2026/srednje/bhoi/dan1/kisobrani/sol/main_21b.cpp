#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Umbrella {
    int a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, N, Q;
    cin >> R >> C >> N >> Q;

    vector<Umbrella> umbrellas;
    for (int i = 0; i < N; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        umbrellas.push_back({a, b});
    }

    sort(umbrellas.begin(), umbrellas.end(),
         [](const Umbrella &x, const Umbrella &y) { return x.a < y.a; });

    // Simulacija bez kaskadiranja (samo jedan red kisobrana)
    // Za svaki kisobran, kapi sa lijeve polovine idu na a-1, sa desne na b+1
    // Kapi izmedju kisobrana padaju ravno
    // Koristimo prefix sume za efikasno racunanje
    vector<int> landing(C + 2, 0);
    for (int c = 1; c <= C; c++) {
        landing[c] = 1;
    }

    for (int j = 0; j < (int)umbrellas.size(); j++) {
        int a = umbrellas[j].a;
        int b = umbrellas[j].b;
        int w = b - a + 1;
        int left_dest = a - 1;
        int right_dest = b + 1;

        int left_count = w / 2;
        int right_count = w / 2;

        for (int c = a; c <= b; c++) {
            landing[c] = 0;
        }

        if (left_dest >= 1 && left_dest <= C) {
            landing[left_dest] += left_count;
        }
        if (right_dest >= 1 && right_dest <= C) {
            landing[right_dest] += right_count;
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
