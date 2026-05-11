#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;

    int count = 0;
    for (ll i = 1; i * i * i * i * i * i <= b; i++) {
        ll val = i * i * i * i * i * i;
        if (val >= a)
            count++;
    }

    cout << count << "\n";
    return 0;
}
