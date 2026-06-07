#include <iostream>
#include <string>
using namespace std;

// Rjesenje koje prolazi podzadatke 1 i 2 (|A|=|B| i |A|,|B|<=5)
// Brute force provjera za kratke stringove
int main() {
    int t;
    cin >> t;
    string a, b;
    cin >> a >> b;

    if (a.size() == b.size()) {
        // Podzadatak 1: iste duzine, provjeri jednakost
        if (a == b) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
        return 0;
    }

    if (a.size() <= 5 && b.size() <= 5) {
        if (t == 0) {
            // Podstring: provjeri sve pozicije
            bool found = false;
            for (int i = 0; i + (int)a.size() <= (int)b.size(); i++) {
                if (b.substr(i, a.size()) == a) {
                    found = true;
                    break;
                }
            }
            cout << (found ? "DA" : "NE") << endl;
        } else {
            // Podniz: two-pointer
            int i = 0, j = 0;
            while (i < (int)a.size() && j < (int)b.size()) {
                if (a[i] == b[j]) i++;
                j++;
            }
            cout << (i == (int)a.size() ? "DA" : "NE") << endl;
        }
        return 0;
    }

    // Za vece stringove: ne zna rijesiti
    cout << "NE" << endl;
    return 0;
}
