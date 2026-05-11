#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll seed_to_pos(ll seed, ll n) {
    if (n == 1) return 0;
    ll half = n / 2;
    ll pair_idx = (seed <= half) ? seed : (n + 1 - seed);
    ll sub_pos = seed_to_pos(pair_idx, half);
    ll within = (seed <= half) ? 0 : 1;
    return 2 * sub_pos + within;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    // Postavi pocetni raspored tablice
    vector<ll> bracket(n);
    for (ll seed = 1; seed <= n; seed++)
        bracket[seed_to_pos(seed, n)] = seed;

    // Simuliraj runde: susjedni parovi igraju, pobjednik napreduje
    int round_num = 0;
    while (bracket.size() > 1) {
        round_num++;
        vector<ll> next;
        for (int i = 0; i < (int)bracket.size(); i += 2) {
            ll s1 = bracket[i];
            ll s2 = bracket[i + 1];

            if ((s1 == a && s2 == b) || (s1 == b && s2 == a)) {
                cout << round_num << "\n";
                return 0;
            }

            // A i B uvijek pobjedjuju, inace pobjedjuje bolji rang
            if (s1 == a || s1 == b) next.push_back(s1);
            else if (s2 == a || s2 == b) next.push_back(s2);
            else next.push_back(min(s1, s2));
        }
        bracket = next;
    }

    return 0;
}
