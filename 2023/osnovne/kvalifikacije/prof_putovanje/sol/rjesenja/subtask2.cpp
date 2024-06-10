// pošto nas zanima distanca od samo jedne tačke, za svaku tačku koju dodamo,
// provjerimo distancu od (0, 0) i provjerimo je li veća od trenutnog maksimuma
// ako jeste trenutni maksimum će postati ta distanca
#include <bits/stdc++.h>
#define mp make_pair
#define all(a) a.begin(), a.end()
#define dist(a, b) (abs(a.first - b.first) + abs(a.second - b.second))

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int max_dist = 0;
    for (int i = 0; i < n; i++) {
        pii a;
        cin >> a.first >> a.second;
        max_dist = max(max_dist, dist(mp(0,0), a));
    }

    while (q--) {
        int t; pii p;
        cin >> t >> p.first >> p.second;
        if (t == 1) {
            cout << max_dist << "\n";
        }
        else 
            max_dist = max(max_dist, dist(mp(0,0), p));
    }
}