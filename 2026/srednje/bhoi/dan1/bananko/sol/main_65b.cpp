#include <iostream>
#include <cmath>
using namespace std;

bool jeKvadrat(int x) {
    for (int i = 1; i <= x; i++) {
        if (i * i == x) return true;
        if (i * i > x) break;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    // k=1
    if (jeKvadrat(n)) { cout << 1 << "\n"; return 0; }

    // k=2
    for (int i = 1; i <= n; i++) {
        if (!jeKvadrat(i)) continue;
        if (jeKvadrat(n - i)) { cout << 2 << "\n"; return 0; }
    }

    // k=3
    for (int i = 1; i <= n; i++) {
        if (!jeKvadrat(i)) continue;
        for (int j = 1; j <= n - i; j++) {
            if (!jeKvadrat(j)) continue;
            if (jeKvadrat(n - i - j)) { cout << 3 << "\n"; return 0; }
        }
    }

    // k=4
    for (int i = 1; i <= n; i++) {
        if (!jeKvadrat(i)) continue;
        for (int j = 1; j <= n - i; j++) {
            if (!jeKvadrat(j)) continue;
            for (int k = 1; k <= n - i - j; k++) {
                if (!jeKvadrat(k)) continue;
                for (int l = 1; l <= n - i - j - k; l++) {
                    if (!jeKvadrat(l)) continue;
                    if (i + j + k + l == n) { cout << 4 << "\n"; return 0; }
                }
            }
        }
    }

    return 0;
}
