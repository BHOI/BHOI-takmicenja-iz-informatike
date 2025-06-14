#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    // Nakon dodavanja poteza, uraditi Bellman-Ford
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

    // cerr << "Ulaz ucitan" << endl;
    
    vector <int> razl_startovi; // Niz svih razlicitih startnih pozicija
    for(int i=0; i < q; i++){
        bool vec_postoji = false;
        for(int j=0; j < razl_startovi.size(); j++){
            if(razl_startovi[j] == s[i]){
                vec_postoji = true;
                break;
            }
        }
        if(!vec_postoji){
            razl_startovi.push_back(s[i]);
        }
    }

    int rs = razl_startovi.size();
    
    // cerr << "Razliciti startovi odrednjeni, velicina: " << razl_startovi.size() << endl;
    // cerr << "Razliciti startovi: ";
    // for(int i = 0; i < rs; i++) {
    //     cerr << razl_startovi[i] << " ";
    // }
    // cerr << endl;
    // cerr << "Svi startovi: ";
    // for(int i = 0; i < q; i++) {
    //     cerr << s[i] << " ";
    // }
    // cerr << endl;

    vector<vector<int>> dist;
    set<int> startao_od;

    for(int i = 0; i < q; i++) {
        // Ako se ne mijenja skup poteza, samo ispisati
        // Inace, uraditi Bellman-Ford sa svih razl_startovi
        int start = s[i];
        int end = t[i];

        if(startao_od.count(start)) {
            // cerr << "Vec je startano od " << start << endl;
            if(dist[start][end] == (1 << 29)) {
                cout << "NEMOGUCE" << endl;
            } else {
                cout << dist[start][end] << endl;
            }
            continue;
        }

        // cerr << "Startam od " << start << endl;

        startao_od.insert(start);
        // Dodajemo novi potez
        a.push_back(start);
        b.push_back(y[start]);
        e.push_back(z[start]);

        dist = vector<vector<int>>(n);

        // cerr << "dist resetovan" << endl;

        for(int j = 0; j < rs; j++) {
            int st = razl_startovi[j];
            // cerr << "Radim Bellman-Ford od " << razl_startovi[j] << endl;
            // Bellman-Ford od st
            dist[st] = vector<int>(n, 1<<29);

            dist[st][st] = 0;
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < a.size(); l++) {
                    int u = a[l];
                    int v = b[l];
                    int w = e[l];

                    dist[st][v] = min(dist[st][v], dist[st][u] + w);
                }
            }
        }

        if(dist[start][end] == (1 << 29)) {
            cout << "NEMOGUCE" << endl;
        } else {
            cout << dist[start][end] << endl;
        }
    }

    return 0;
}