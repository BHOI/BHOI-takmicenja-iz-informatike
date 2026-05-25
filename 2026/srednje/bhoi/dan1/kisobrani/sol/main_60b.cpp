#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, N, Q;
    cin >> R >> C >> N >> Q;

    vector<vector<pair<int, int>>> umbrellas(R + 1);
    for (int i = 0; i < N; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        umbrellas[r].push_back({a, b});
    }
    for (int r = 1; r <= R; r++)
        sort(umbrellas[r].begin(), umbrellas[r].end());

    // by_dest[d] = (orig_lo, orig_hi): original cols [orig_lo..orig_hi] all currently
    // tracked at destination d. dest is non-decreasing in orig col (provable by induction),
    // so orig ranges across runs are always contiguous -- no gaps possible.
    map<int, pair<int, int>> by_dest;
    for (int c = 1; c <= C; c++)
        by_dest.emplace_hint(by_dest.end(), c, make_pair(c, c));

    // Merge all runs with current dest in [lo, hi] into a single run at new_dest.
    auto merge_range = [&](int lo, int hi, int new_dest) {
        map<int, pair<int, int>>::iterator it = by_dest.lower_bound(lo);
        map<int, pair<int, int>>::iterator end_it = by_dest.upper_bound(hi);
        if (it == end_it) return;

        int mlo = it->second.first;
        int mhi = prev(end_it)->second.second;
        by_dest.erase(it, end_it);

        map<int, pair<int, int>>::iterator ex = by_dest.find(new_dest);
        if (ex != by_dest.end()) {
            mlo = min(mlo, ex->second.first);
            mhi = max(mhi, ex->second.second);
            by_dest.erase(ex);
        }
        by_dest[new_dest] = {mlo, mhi};
    };

    for (int r = 1; r <= R; r++) {
        for (int i = 0; i < (int)umbrellas[r].size(); i++) {
            int a = umbrellas[r][i].first;
            int b = umbrellas[r][i].second;
            int mid = a + (b - a + 1) / 2;
            merge_range(a, mid - 1, a - 1);
            merge_range(mid, b, b + 1);
        }
    }

    vector<ll> prefix(C + 2, 0);
    for (map<int, pair<int, int>>::iterator it = by_dest.begin(); it != by_dest.end(); ++it) {
        int d = it->first;
        ll cnt = it->second.second - it->second.first + 1;
        if (d >= 1 && d <= C)
            prefix[d] += cnt;
    }
    for (int i = 1; i <= C; i++)
        prefix[i] += prefix[i - 1];

    for (int q = 0; q < Q; q++) {
        int L, D;
        cin >> L >> D;
        cout << prefix[D] - prefix[L - 1] << "\n";
    }

    return 0;
}
