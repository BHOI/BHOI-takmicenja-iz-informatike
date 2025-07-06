#include <iostream>
#include <string.h>
using namespace std;

char povrsina[3][4];

#define nepravilno "nepravilno"
#define pobjeda_o "po"
#define pobjeda_x "px"
#define x_na_potezu "x"
#define o_na_potezu "o"
#define nerijeseno "nerijeseno"

int main() {
    cin >> povrsina[0] >> povrsina[1] >> povrsina[2];
    // koliko puta imamo x
    int x = 0;
    // koliko puta imamo o
    int o = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (povrsina[i][j] == 'X') {
                x++;
            }
            if (povrsina[i][j] == 'O') {
                o++;
            }
        }
    }
    // posto je uvijek X prvi na potezu, moguce je jedino da imamo
    // X za jedan vise od O, ili jednak broj.
    if (x > o + 1 || x < o) {
        cout << nepravilno;
        return 0;
    }
    // da li je X pobijedio u ovoj rundi
    bool xP = false;
    // da li je O pobijedio u ovoj rundi
    bool oP = false;
    for (int i=0; i<3; i++) {
        // horizontalno
        if (strcmp(povrsina[i], "XXX") == 0) {
            xP = true;
        }
        if (strcmp(povrsina[i], "OOO") == 0) {
            oP = true;
        }
        // vertikalno
        if (povrsina[0][i] == 'X' && povrsina[1][i] == 'X' && povrsina[2][i] == 'X') {
            xP = true;
        }
        if (povrsina[0][i] == 'O' && povrsina[1][i] == 'O' && povrsina[2][i] == 'O') {
            oP = true;
        }
    }
    // dijagonalno
    if (povrsina[0][0] == povrsina[1][1] &&
        povrsina[1][1] == povrsina[2][2] &&
        povrsina[1][1] != '.'
    ) {
        if (povrsina[1][1] == 'X') {
            xP = true;
        } else {
            oP = true;
        }
    }
    if (povrsina[2][0] == povrsina[1][1] &&
        povrsina[1][1] == povrsina[0][2] &&
        povrsina[1][1] != '.'
    ) {
        if (povrsina[1][1] == 'X') {
            xP = true;
        } else {
            oP = true;
        }
    }
    // ukoliko su oba pobijedila, to nije pravilno
    if (xP && oP) {
        cout << nepravilno;
    // ukoliko je jedan od igraca pobijedio, ispisati koji je pobjednik
    } else if (xP || oP) {
        // ukoliko je x pobijedio, moramo imati tacno x-1 oksova
        // ukoliko je o pobijedio, moramo imati tacno o iksova
        if ((xP && x == o + 1) || (oP && x == o)) {
            cout << (xP ? pobjeda_x : pobjeda_o);
        } else {
            cout << nepravilno;
        }
    // nijedan od igraca nije pobijedio. Ukoliko imamo 9 polja popunjenih onda
    // je igra gotova nerijesenim rezultatom.
    } else if (x + o == 9) {
        cout << nerijeseno;
    } else {
        // ukoliko imamo jednak broj X i O onda je X na potezu.
        cout << ((x == o) ? x_na_potezu : o_na_potezu);
    }
}