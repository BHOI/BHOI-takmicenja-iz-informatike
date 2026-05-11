#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;

    // Racuna samo Menhetensku udaljenost i ispisuje je 3 puta.
    // Tacno samo kada su sve tri udaljenosti jednake,
    // npr. kada je razlika samo po jednoj osi (y1=y2, z1=z2).
    ll dx = abs(x2 - x1);
    ll dy = abs(y2 - y1);
    ll dz = abs(z2 - z1);
    ll manhattan = dx + dy + dz;

    cout << manhattan << "\n";
    cout << manhattan << "\n";
    cout << manhattan << "\n";

    return 0;
}
