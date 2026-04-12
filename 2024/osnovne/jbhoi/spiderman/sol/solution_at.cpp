// Solution: Admir Tuzovic
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1e7;

int N;
int H[MAXN];

// IDEJA: Uvijek mozemo skociti na najvecu zgradu.
// Na pocetku to je najveca zgrada, i to prva na koju naidjemo (ako ima vise sa istom maksimalnom visinom).
// Onda trazimo prvu narednu najvecu zgradu u preostalom dijelu niza.
// Pa onda trazimo prvu narednu najvecu zgradu u narednom preostalom dijelu niza, itd.
// Medjutim to je presporo, ali ono sto mozemo zakljuciti da je da nam trebaju najvece zgrade u nizu,
// gledajuci niz od neke pozicije i do N-1.
// To mozemo iskoristiti tako sto cemo prolaziti niz unazad, 
// i cim naidjemo na novu maksimalnu visinu, to predstavlja skok.
static void solve() {

    cin >> N;

    // Ucitamo sve visine.
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    // Minimalno jedan skok mora biti napravljen na zadnju zgradu.
    int jumps = 1;

    // Krenemo od toga da je najveca visina = visina posljednje zgrade.
    int maxHeight = H[N-1];

    // Krecemo se unazad po visinama.
    for(int i = N-2; i >= 0; i--) {

        // Ako naidjemo na zgradu cija je visina veca ili jednaka prethodnoj najvecoj.
        if(H[i] >= maxHeight) {

            // Na tu zgradu se mora skociti
            jumps++;

            // Tu zgradu oznacimo kao najvecu pronadjenu.
            maxHeight = H[i];
        }
    }

    // Ispisemo ukupan broj neophodnih skokova.
    cout << jumps << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
