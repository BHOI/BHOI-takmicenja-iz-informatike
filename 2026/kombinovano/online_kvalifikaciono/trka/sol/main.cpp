#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;

    ll dx = abs(x2 - x1);
    ll dy = abs(y2 - y1);
    ll dz = abs(z2 - z1);

    // Cebisevljeva udaljenost: max apsolutnih razlika
    ll chebyshev = max({dx, dy, dz});

    // Euklidska udaljenost: zaokruzeno na dolje
    ll dist_sq = dx * dx + dy * dy + dz * dz;
    ll euclidean = (ll)sqrt((double)dist_sq);
    while ((euclidean + 1) * (euclidean + 1) <= dist_sq)
        euclidean++;

    // Menhetenska udaljenost: suma apsolutnih razlika
    ll manhattan = dx + dy + dz;

    cout << chebyshev << "\n";
    cout << euclidean << "\n";
    cout << manhattan << "\n";

    return 0;
}
