// za svaki upit tipa 1 pogledamo distancu između date tačke i našeg niza tački
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
    vector<pii> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;
    
    while (q--) {
        int t;
        cin >>t;
        if (t == 1) {
            pii my;
            cin >> my.first >> my.second;
            int mini = 0;
            for (pii s : points)
                mini = max(mini, dist(s, my));
            cout << mini << "\n";
        }
        else {
            pii my;
            cin >> my.first >> my.second;
            points.push_back(my);
        }
    }
}