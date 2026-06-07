#include <iostream>
#include <string>
using namespace std;

// Rjesenje koje prolazi podzadatke 1, 2 i 3 (|A|=|B|, |A|,|B|<=5, T=0)
// Zna provjeriti podstring, ali ne i podniz za velike stringove
int main() {
    int t;
    cin >> t;
    string a, b;
    cin >> a >> b;

    if (t == 0) {
        // Podstring provjera
        if (b.find(a) != string::npos) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    } else {
        // Podniz: zna samo za jednake duzine ili kratke stringove
        if (a.size() == b.size()) {
            cout << (a == b ? "DA" : "NE") << endl;
        } else if (a.size() <= 5 && b.size() <= 5) {
            int i = 0, j = 0;
            while (i < (int)a.size() && j < (int)b.size()) {
                if (a[i] == b[j]) i++;
                j++;
            }
            cout << (i == (int)a.size() ? "DA" : "NE") << endl;
        } else {
            cout << "NE" << endl;
        }
    }
    return 0;
}
