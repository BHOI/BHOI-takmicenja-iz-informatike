#include <iostream>
#include <cmath>
using namespace std;

bool jestePotpuniKvadrat(int x) {
    int s = (int)sqrt((double)x);
    return s * s == x;
}

int main() {
    int n;
    cin >> n;

    // Podzadatak 4: svi prosti faktori oblika 4k+1
    // Po Fermatovom teoremu, takvi brojevi su zbir dva kvadrata
    // Odgovor je 1 ako je N potpuni kvadrat, inace 2

    if (jestePotpuniKvadrat(n)) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }

    return 0;
}
