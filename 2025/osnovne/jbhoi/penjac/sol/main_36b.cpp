#include <iostream>
#include <vector>

using namespace std;

int main(){
    // Puno upita, ali uvijek iz iste pocetne tacke
    // Odmah dodati potez koji ce se dodati, uraditi Bellman-Ford jednom
    // i samo ispisivati odgovore na upite

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(m), b(m), e(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> e[i];
    }

    vector<int> y(n), z(n);
    for(int i = 0; i < n; i++){
        cin >> y[i] >> z[i];
    }

    vector<int> s(q), t(q);
    for(int i = 0; i < q; i++){
        cin >> s[i] >> t[i];
    }
    
    int start = s[0];
    // Niz udaljenosti od pocetne tacke (ista pocetna tacka za sve upite)
    vector<int> dist(n, 1e9);
    dist[start] = 0;

    // Dodajemo potez koji ce se otkljucati iz pocetne tacke
    a.push_back(start);
    b.push_back(y[start]);
    e.push_back(z[start]);

    // Bellman-Ford algoritam
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m + 1; j++) {
            if(dist[a[j]] != 1e9) {
                dist[b[j]] = min(dist[b[j]], dist[a[j]] + e[j]);
            }
        }
    }

    // Jednom smo izracunali udaljenosti, sada samo ispisujemo odgovore na upite
    for(int i = 0; i < q; i++) {
        if(dist[t[i]] != 1e9){
            cout << dist[t[i]] << endl;
        } else {
            cout << "NEMOGUCE" << endl;
        }
    }

    return 0;
}