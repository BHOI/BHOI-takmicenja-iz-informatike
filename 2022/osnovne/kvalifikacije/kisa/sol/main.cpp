#include <iostream>
#include <string.h>
using namespace std;

char ekran[1000][1000];

int main() {
    int sirina, visina;
    cin >> sirina >> visina;
    for (int i=0; i<visina; i++) {
        cin >> ekran[i];
    }
    int rezultat = 0;
    for (int i=0; i<sirina; i++) {
        int trenutna = 0;
        for (int j=0; j<visina; j++) {
            if (ekran[j][i] == '#') {
                trenutna++;
            } else {
                rezultat = max(trenutna, rezultat);
                trenutna = 0;
            }
        }
        rezultat = max(trenutna, rezultat);
    }
    cout << rezultat << endl;
}