#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> start_stanje(n), cilj_stanje(n), hist(3);
    for(int i = 0; i < n; i++) {
        cin >> start_stanje[i];
        hist[start_stanje[i]]++;  // Brojimo koliko ima nula, jedinica i dvica
    }

    for(int i = 0; i < hist[1]; i++) {
        cilj_stanje[i] = 1;
    }
    for(int i = n - 1; i >= n - hist[2]; i--) {
        cilj_stanje[i] = 2;
    }
    
    queue<vector<int>> q_stanja;
    queue<vector<int>> q_potezi;
    q_stanja.push(start_stanje);
    q_potezi.push(vector<int>());  // Prazan vektor poteza za pocetno stanje

    while(q_stanja.front() != cilj_stanje) {
        vector<int> tr_stanje = q_stanja.front();
        vector<int> tr_potezi = q_potezi.front();
        int br_poteza = tr_potezi.size();
        q_stanja.pop();
        q_potezi.pop();
        
        // Generisemo nova stanja
        for(int i = 0; i < n - 1; i++) {
            // Provjeriti poteze po 1
            if(tr_stanje[i] == 0 && tr_stanje[i + 1] == 1) {
                vector<int> novo_stanje = tr_stanje;
                swap(novo_stanje[i], novo_stanje[i + 1]);
                q_stanja.push(novo_stanje);
                
                vector<int> novi_potezi = tr_potezi;
                novi_potezi.push_back(i + 1);  // Lijeva cizma na poziciji i + 1 je skocila
                q_potezi.push(novi_potezi);
            } 
            else if(tr_stanje[i] == 2 && tr_stanje[i + 1] == 0) {
                vector<int> novo_stanje = tr_stanje;
                swap(novo_stanje[i], novo_stanje[i + 1]);
                q_stanja.push(novo_stanje);

                vector<int> novi_potezi = tr_potezi;
                novi_potezi.push_back(i);  // Desna cizma na poziciji i je skocila
                q_potezi.push(novi_potezi);
            }

            if(i < n - 1 && tr_stanje[i + 1] != 0) {
                if(tr_stanje[i] == 0 && tr_stanje[i + 2] == 1) {
                    vector<int> novo_stanje = tr_stanje;
                    swap(novo_stanje[i], novo_stanje[i + 2]);
                    q_stanja.push(novo_stanje);

                    vector<int> novi_potezi = tr_potezi;
                    novi_potezi.push_back(i + 2);  // Lijeva cizma na poziciji i + 2 je skocila
                    q_potezi.push(novi_potezi);
                }
                else if(tr_stanje[i] == 2 && tr_stanje[i + 2] == 0) {
                    vector<int> novo_stanje = tr_stanje;
                    swap(novo_stanje[i], novo_stanje[i + 2]);
                    q_stanja.push(novo_stanje);

                    vector<int> novi_potezi = tr_potezi;
                    novi_potezi.push_back(i);  // Desna cizma na poziciji i je skocila
                    q_potezi.push(novi_potezi);
                }
            }
        }
    }

    // Prikazujemo rjesenje u minimalnom broju poteza
    vector <int> optimalni_potezi = q_potezi.front();

    cout << optimalni_potezi.size() << endl;
    for(int i = 0; i < optimalni_potezi.size(); i++) {
        cout << optimalni_potezi[i] + 1 << " ";  // Povećavamo indeks za 1 prilikom ispisa
    }
    cout << endl;

    return 0;
}