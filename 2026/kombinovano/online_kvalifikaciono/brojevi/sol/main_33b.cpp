#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;

    // Prolazi kroz sve brojeve od A do B i provjerava
    // da li je 6. korijen cijeli broj koristeci pow funkciju.
    // Previse sporo za velike raspone.
    int count = 0;
    for (ll x = a; x <= b; x++) {
        ll root = (ll)round(pow((double)x, 1.0 / 6.0));
        ll check = (ll)round(pow((double)root, 6.0));
        if (check == x) count++;
    }

    cout << count << "\n";
    return 0;
}
