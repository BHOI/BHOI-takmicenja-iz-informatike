// Solved: Admir Tuzovic
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6;

ll N; // Ukupan broj ucenika.
ll K; // Ukupan broj parova prijatelja.
ll S; // Ukupan broj parova neprijatelja. :)

// Adjacency list za parove prijatelja.
vector<int> adjs[MAXN+1];

// Niz koji sadrzi informaciju kojoj grupi prijatelja pripada neki ucenik.
int assignments[MAXN+1];

static void solve() {

    // Ucitamo osnovne informacije o razredu i parovima.
    cin >> N >> K >> S;

    // Prodjemo kroz osnovne postavke za sve ucenike.
    for(int i = 1; i <= N; i++) {

        // Nijedan ucenik trenutno nije ni u jednoj grupi.
        assignments[i] = -1;

        // I nema medjusobno nikakvih prijateljstava izmedju ucenika.
        adjs[i].clear(); 
    }

    // Ucitavamo parove prijatelja i medjusobno ih povezujemo u 
    // adjacency listi.
    int s1,s2;
    for(int i = 0; i < K; i++) {
        cin >> s1 >> s2;
        adjs[s1].push_back(s2);
        adjs[s2].push_back(s1);
    }

    // Broja grupa prijatelja koje cemo odrediti.
    int groups = 0;

    // Prolazimo kroz listu svih ucenika kako bismo odredili
    // sve prijatelje tih ucenika.
    for(int i = 1; i <= N; i++) {

        // Ako je ucenik vec dodijeljen nekoj grupi.
        if(assignments[i] != -1) {
            // Preskacemo.
            continue;
        }

        // Povecamo broj pronadjenih grupa za 1.
        groups++;

        // BFS implementacija.
        queue<int> q;
        // Ubacimo trenutnog ucenika u queue.
        q.push(i);
        // I dodijelimo ga u prvu grupu.
        assignments[i] = groups;

        // Sve dok queue nije prazan.
        while(!q.empty()) {

            // Skidamo prvi element iz queue.
            int u = q.front();
            q.pop();

            // Prolazimo kroz njegovu adjacency listu, sto je u sustini lista
            // njegovih prijatelja.
            for(int v : adjs[u]) {
                
                // Ako prijatelj nije prethodno ubacen u grupu.
                if(assignments[v] == -1) {

                    // Ubacimo ga u queue da procesiramo njegove prijatelje.
                    q.push(v);

                    // A njega stavimo u trenutnu grupu.
                    assignments[v] = groups;
                }
            }

        }
    }

    // Adjecency lista koju cemo koristiti da oznacimo koje grupe
    // medjusobno su povezane na nacin da u jednoj grupi jedan ucenik
    // ne moze biti sa ucenikom u drugoj grupi.
    vector<vector<int>> adjgrp(groups+1);

    // Pretpostavimo da je moguce ucenike razvrstati u takve grupe u kojima
    // su svi prijatelji unutar jedne grupe.
    bool isPossible = true;

    // Procesiramo sve ulazne parove neprijateljstava.
    for(int i = 0; i < S; i++) {
        cin >> s1 >> s2;

        // Odredimo za svakog ucenika iz para u kojoj grupi se nalazi.
        int isl1 = assignments[s1];
        int isl2 = assignments[s2];

        // Ako se dva ucenika nalaze u istoj grupi a nisu prijatelji,
        // to znaci da nije moguce organizovati grupe da je sve zadovoljeno.
        if(isl1 == isl2) {
            isPossible = false;
        } else {
            // U suprotnom, povezemo te dvije grupe, da znamo da se one
            // ne smiju spojiti zajedno u jednu od dvije velike grupe koje trazimo.
            adjgrp[isl1].push_back(isl2);
            adjgrp[isl2].push_back(isl1);
        }
    }

    // Ako smo odredili da postoji grupa u kojoj su i prijatelji i neprijatelji.
    if(!isPossible) {
        // Dioba nije moguca.
        cout << "NE" << '\n';
        return;
    }

    // Ako smo odredili da postoji samo jedna grupa, onda nije uopste
    // moguce napraviti dvije grupe.
    if(groups == 1) {
        cout << "NE" << '\n';
        return;
    }

    // Grupe cemo sada podijeliti u dvije skupine, tako sto cemo jednu skupinu
    // da bojimo sa 0 a drugu sa 1.
    // U ovom nizu cuvamo informacije kojom bojom je obojena grupa.
    // Na pocetku nijedna grupa nije obojena, pa je vrijednost -1.
    vector<int> colors(groups+1, -1);

    // Pretpostavimo da ne postoje neparni ciklusi u grafu.
    // Ako postoje, onda graf nije biparitetni.
    bool hasOddCycles = false;

    // Prolazimo sada kroz sve grupe koje smo odredili.
    for(int grp = 1; grp <= groups; grp++) {

        // Ako je grupa prethodno obojena, preskacemo je.
        if(colors[grp] != -1) {
            continue;
        }

        // BFS implementacija za grupe.
        queue<int> gq;
        // Grupu ubacimo u queue.
        gq.push(grp);
        // Obojimo je sa 0.
        colors[grp] = 0;

        // Sve dok u queue imamo jos neprocesiranih grupa.
        while(!gq.empty()) {

            // Preuzmemo narednu grupu.
            int i = gq.front();
            gq.pop();

            // Obidjemo sve grupe koje su povezane sa njom.
            for(int j : adjgrp[i]) {

                // Ako susjedna povezana grupa nije obojena.
                if(colors[j] == -1) {
                    // Ubacimo je u queue.
                    gq.push(j);
                    // I obojimo suprotnom bojom.
                    colors[j] = 1 - colors[i];
                } else {
                    // Ako je boja grupe ista kao i boja susjedne grupe.
                    if(colors[j] == colors[i]) {
                        // To znaci da su grupe dio ciklusa sa neparnim brojem grupa.
                        // Sto znaci da graf nije biparitetan.
                        hasOddCycles = true;
                        break;
                    }
                }
            }

            if(hasOddCycles) {
                break;
            }

        }

        if(hasOddCycles) {
            break;
        }

    }

    // Ako postoje neparni ciklusi, dioba nije moguca.
    if(hasOddCycles) {
        cout << "NE" << '\n';
    } else {
        cout << "DA" << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R;
    cin >> R;

    while (R--) {
        solve();
    }

    return 0;
}
