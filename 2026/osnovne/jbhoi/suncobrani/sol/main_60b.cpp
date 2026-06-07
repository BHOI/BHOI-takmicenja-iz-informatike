#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> A(n), B(n), D(n);
    int max_b = 0, min_a = 100001;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> D[i];
        max_b = max(max_b, B[i]);
        min_a = min(min_a, A[i]);
    }

    // Difference array za zastitu po poljima
    vector<int> diff(max_b + 2, 0);
    for (int i = 0; i < n; i++) {
        diff[A[i]] += D[i];
        diff[B[i] + 1] -= D[i];
    }

    // Zastita na svakom polju (indeksirano od 1 do max_b)
    vector<int> prot(max_b + 2, 0);
    for (int i = 1; i <= max_b; i++) {
        prot[i] = prot[i - 1] + diff[i];
    }

    // Prefix sume zastite za brzo racunanje suma segmenata
    vector<int> psum(max_b + 2, 0);
    for (int i = 1; i <= max_b; i++) {
        psum[i] = psum[i - 1] + prot[i];
    }

    // Iteriramo sve moguce pocetne pozicije Dariza
    // Jedino pozicije koje pokrivaju barem jedno suncobransko polje su zanimljive
    // (jer van suncobrana zastita je 0, a zagarantovano postoji optimum > 0)
    // Raspon: [min_a - l + 1, max_b]
    int best_start = min_a - l + 1;
    int best_sum = -1;
    int lo, hi, s;

    for (int x = min_a - l + 1; x <= max_b; x++) {
        lo = max(x, 1);
        hi = min(x + l - 1, max_b);
        s = 0;
        if (lo <= hi) {
            s = psum[hi] - psum[lo - 1];
        }
        if (s > best_sum) {
            best_sum = s;
            best_start = x;
        }
    }

    cout << best_start << " " << (best_start + l - 1) << endl;

    return 0;
}
