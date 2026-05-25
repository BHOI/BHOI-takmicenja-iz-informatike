#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int R, C, N, Q;
vector<pair<int, int>> umbrellas[101];

// Simulira kap sa kolone col, vraca kolonu na koju padne na tlo
int simulate(int col) {
    for (int row = 1; row <= R; row++) {
        const vector<pair<int, int>> &v = umbrellas[row];
        if (v.empty()) continue;
        int lo = 0, hi = (int)v.size() - 1, idx = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid].first <= col) {
                idx = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (idx >= 0 && col <= v[idx].second) {
            int a = v[idx].first;
            int b = v[idx].second;
            int w = b - a + 1;
            if (col < a + w / 2) {
                col = a - 1;
            } else {
                col = b + 1;
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
        sort(umbrellas[row].begin(), umbrellas[row].end());
    }

    for (int q = 0; q < Q; q++) {
        int L, D;
        cin >> L >> D;

        // f(c) = simulate(c) je neopadajuca, koristimo binarnu pretragu
        // Najmanji c takav da f(c) >= L
        int lo = 1, hi = C, left_bound = C + 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (simulate(mid) >= L) {
                left_bound = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // Najveci c takav da f(c) <= D
        lo = 1;
        hi = C;
        int right_bound = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (simulate(mid) <= D) {
                right_bound = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        int ans = 0;
        if (left_bound <= right_bound) {
            ans = right_bound - left_bound + 1;
        }
        cout << ans << "\n";
    }

    return 0;
}
