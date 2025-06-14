#include <iostream>

using namespace std;

long long k[100010];

int main() {
    long long n, m;
    cin >> n >> m;

    for(int i=0; i < n; i++) {
        cin >> k[i];
    }

    long long l = 0, r = 0, suma = k[0], min_udaljenost = n;

    while(r < n) {
        if(suma < m) {
            r++;
            if(r < n) {
                suma += k[r];
            }
        } else {
            min_udaljenost = min(min_udaljenost, r - l);
            suma -= k[l];
            l++;
        }
    }

    cout << min_udaljenost << endl;

    return 0;
}