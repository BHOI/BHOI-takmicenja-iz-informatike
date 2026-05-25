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
    for (int i = 1; i <= n; i++) {
        if(jeKvadrat(i) && i == n) { 
            cout << 1 << "\n"; 
            return 0; 
        }
    }

    // k=2
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(jeKvadrat(i) && jeKvadrat(j) && i + j == n) { 
                cout << 2 << "\n"; 
                return 0; 
            }
        }
    }

    // k=3
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if(jeKvadrat(i) && jeKvadrat(j) && jeKvadrat(k) && i + j + k == n) { 
                    cout << 3 << "\n"; 
                    return 0; 
                }
            }
        }
    }

    // k=4
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                    if(jeKvadrat(i) && jeKvadrat(j) && jeKvadrat(k) && jeKvadrat(l) && i + j + k + l == n) { 
                        cout << 4 << "\n"; 
                        return 0; 
                    }
                }
            }
        }
    }

    return 0;
}
