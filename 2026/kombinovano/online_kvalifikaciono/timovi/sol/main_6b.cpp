#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a1, b1, a2, b2;
    // M = 2: procitaj obje ivice, provjeri da li formiraju ciklus duzine 2
    cin >> a1 >> b1;
    if (m == 2) {
        cin >> a2 >> b2;
        // Ako su ivice a->b i b->a, formiraju tim od 2
        if ((a1 == b2 && b1 == a2)) {
            cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
    } else {
        cout << 1 << "\n";
    }

    return 0;
}
