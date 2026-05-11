#include <iostream>
using namespace std;
typedef long long ll;

// Pretvara rang (1-indeksiran) u poziciju u tablici (0-indeksirana).
// Rekurzivno: rang s igra protiv ranga (n+1-s).
// Taj par se smjesta na poziciju seed_to_pos(min(s, n+1-s), n/2).
// Bolji rang (<=n/2) dobija parnu poziciju, losiji neparnu.
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

    ll pos_a = seed_to_pos(a, n);
    ll pos_b = seed_to_pos(b, n);

    // Runda u kojoj se susrecu:
    // odredjena je najvisim bitom od (pos_a XOR pos_b)
    ll xor_val = pos_a ^ pos_b;
    int round = 0;
    while (xor_val > 0) {
        round++;
        xor_val >>= 1;
    }

    cout << round << "\n";
    return 0;
}
