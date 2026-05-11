#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    int sr, sc, cr, cc;
    for (int i = 0; i < h; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < w; j++) {
            if (row[j] == 'S') { sr = i; sc = j; }
            if (row[j] == 'C') { cr = i; cc = j; }
        }
    }

    // Nema zidova: odgovor je 1 ako su u istom redu ili koloni, inace 2
    if (sr == cr || sc == cc)
        cout << 1 << "\n";
    else
        cout << 2 << "\n";

    return 0;
}
