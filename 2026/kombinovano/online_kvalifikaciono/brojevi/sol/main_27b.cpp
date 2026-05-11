#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;

    // Zna samo za tri najmanja sesta stepena: 1, 64, 729
    int count = 0;
    if (a <= 1 && 1 <= b) count++;
    if (a <= 64 && 64 <= b) count++;
    if (a <= 729 && 729 <= b) count++;

    cout << count << "\n";
    return 0;
}
