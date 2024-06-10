#include <bits/stdc++.h>
#define mp make_pair
#define val(o, pnt) (pnt.first * mults[o].first + pnt.second * mults[o].second)
#define dist(a, b) (abs(a.first - b.first) + abs(a.second - b.second))

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<pii> mults = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<pii> best(4, mp(1e9, 1e9));
    for (int i = 0; i < n; i++) {
        pii my;
        cin >> my.first >> my.second;
        for (int j = 0; j < 4; j++)
            if (best[j] == mp((int)1e9, (int)1e9) or val(j, my) > val(j, best[j]))
                best[j] = my;
    }

    while (q--) {
        int t;
        cin >> t;
        pii my;
        cin >> my.first >> my.second;
        if (t == 1) {
            int out = 0;
            for (pii a : best)
                out = max(out, dist(a, my));
            cout << out << "\n";
        }
        else if (t == 2) {
            for (int j = 0; j < 4; j++)
                if (val(j, my) > val(j, best[j]))
                    best[j] = my;
        }
    }
}