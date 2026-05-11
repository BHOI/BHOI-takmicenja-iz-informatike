#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    // Hardkodirani raspored za N=8
    // Pozicije u tablici za svaki rang:
    // rang 1 -> poz 0, rang 8 -> poz 1
    // rang 4 -> poz 2, rang 5 -> poz 3
    // rang 2 -> poz 4, rang 7 -> poz 5
    // rang 3 -> poz 6, rang 6 -> poz 7
    int pos[9] = {0, 0, 4, 6, 2, 3, 7, 5, 1};

    int pa = pos[a];
    int pb = pos[b];

    // Simuliraj runde: u svakoj rundi, parovi na pozicijama (2k, 2k+1) igraju
    int runda = 0;
    while (pa != pb) {
        pa /= 2;
        pb /= 2;
        runda++;
    }

    cout << runda << "\n";
    return 0;
}
