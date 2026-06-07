#include <iostream>
#include <string>
using namespace std;

// Rjesenje koje prolazi samo podzadatak 1 (|A| = |B|)
// Provjerava samo jednakost stringova
int main() {
    int t;
    cin >> t;
    string a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "DA" << endl;
    } else {
        cout << "NE" << endl;
    }
    return 0;
}
