#include <iostream>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    // Podzadatak 1: N = 1, samo jedan suncobran
    int a, b, d;
    cin >> a >> b >> d;

    int sirina = b - a + 1;

    // Dvije smislene pozicije:
    // 1. Lijevi kraj prozora na pocetku suncobrana: pocetak = a
    // 2. Desni kraj prozora na kraju suncobrana: pocetak = b - l + 1
    // Ako je l >= sirina, obje daju istu pokrivenost; uzimamo prvu (manji indeks)
    // Ako je l < sirina, pozicija 1 i 2 su razlicite ali daju isti overlap = l
    int start1 = a;
    int start2 = b - l + 1;

    // start2 <= start1 kada je l >= sirina, tada je start2 manji (ili jednak)
    if (start2 < start1) {
        cout << start2 << " " << (start2 + l - 1) << endl;
    } else {
        cout << start1 << " " << (start1 + l - 1) << endl;
    }

    return 0;
}
