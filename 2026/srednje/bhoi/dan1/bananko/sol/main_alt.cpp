#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int lim = (int)sqrt((double)n);

    for (int i = 1; i <= lim; i++) {
        if (i * i == n) { cout << 1 << "\n"; return 0; }
    }

    for (int i = 1; i <= lim; i++) {
        for (int j = 1; j <= lim; j++) {
            if (i * i + j * j == n) { cout << 2 << "\n"; return 0; }
        }
    }

    for (int i = 1; i <= lim; i++) {
        for (int j = 1; j <= lim; j++) {
            for (int k = 1; k <= lim; k++) {
                if (i * i + j * j + k * k == n) { cout << 3 << "\n"; return 0; }
            }
        }
    }

    for (int i = 1; i <= lim; i++) {
        for (int j = 1; j <= lim; j++) {
            for (int k = 1; k <= lim; k++) {
                for (int l = 1; l <= lim; l++) {
                    if (i * i + j * j + k * k + l * l == n) { cout << 4 << "\n"; return 0; }
                }
            }
        }
    }

    return 0;
}
