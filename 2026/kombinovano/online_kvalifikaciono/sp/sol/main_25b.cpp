#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    // Rjesava podzadatak 2: B = A + 1
    // Runda = log2(N) - v2(A), gdje je v2(A) broj trailing nula u A
    int log_n = 0;
    ll tmp = n;
    while (tmp > 1) { log_n++; tmp /= 2; }

    int v2 = 0;
    tmp = a;
    while (tmp % 2 == 0) { v2++; tmp /= 2; }

    cout << log_n - v2 << "\n";
    return 0;
}
