#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> A(n), B(n), D(n);
    int max_b = 0, min_a = 100001;
    vector<int> prot(100002, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> D[i];
        max_b = max(max_b, B[i]);
        min_a = min(min_a, A[i]);
        prot[A[i]] += D[i];
    }

    // Prefix sume zastite za brzo racunanje suma segmenata
    vector<int> psum(max_b + 2, 0);
    for (int i = 1; i <= max_b; i++) {
        psum[i] = psum[i - 1] + prot[i];
    }

    // Sliding window duzine l, racunaj sumu zastite u prozoru, nadji maksimum
    int best_start = min_a - l + 1;
    int best_sum = -1;

    for (int x = min_a - l + 1; x <= max_b; x++) {
        int lo = max(x, 1);
        int hi = min(x + l - 1, max_b);
        int s = 0;
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
