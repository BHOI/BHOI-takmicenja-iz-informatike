#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, K;
    cin >> A >> B >> K;

    long long ukupnoVrijeme, ispred;

    if (B <= A) {
        ukupnoVrijeme = (K + 1) * A + B;
        ispred = 0;
    } else {
        ukupnoVrijeme = A + (K + 1) * B;
        ispred = K - (K * A) / B;
    }

    cout << ukupnoVrijeme << " " << ispred << "\n";
    return 0;
}