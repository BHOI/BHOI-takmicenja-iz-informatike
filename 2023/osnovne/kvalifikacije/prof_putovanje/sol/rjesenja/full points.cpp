// formula za manhattan distance je slijedeća:
// |x1 - x2| + |y1 - y2|
// = max(x1 - x2, x2 - x1) + max(y1 - y2, y2 - y1)
// = max(x1 - x2 + y1 - y2, x1 - x2 + y2 - y1, x2 - x1 + y1 - y2, x2 - x1 + y2 - y1)
// kada preuredimo članove dobijemo
// = max(x1 + y1 - x2 - y2, x1 - y1 - x2 + y2, -x1 + y1 + x2 - y2, -x1 - y1 + x2 + y2)
// recimo da je tačka od koje želimo izračunati (x1, y1)
// to znači da u izrazu iznad mi jedino možemo promijeniti x2 i y2
// u svakom djelu mi želimo maksimizirati ono što možemo promijeniti da dobijemo maksimalan rezultat
// djelovi koje maksimiziramo su: -x2 - y2, -x2 + y2, x2 - y2, x2 + y2
// primjetimo da za bilo koju tačku, kada tražimo najudaljeniju tačku, uvijek će biti jedna od 4 tačke to su
// one sa maksimalnim (-x - y), (-x + y), (x - y) i (x + y)
// ostane nam samo da pamtimo koordinate tačaka sa tim maksimalnim vrijednostima i za svaki upit prvog tipa pronađemo najdalju tačku od ove 4
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