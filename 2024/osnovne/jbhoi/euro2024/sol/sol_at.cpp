// Solved: Admir Tuzovic
#include <bits/stdc++.h>

using namespace std;

const int MAXT = 100;

int T;
int U;

// Cuvamo sve neophodne informacije o timu.
struct Team {
    string name; // Naziv tima.
    int index = 0; // Redni broj tima odredjen prilikom ucitavanja.
    int score = 0; // Ukupan broj poena koje je ostvario tim u svim odigranim utakmicama.
    int goals = 0; // Ukupan broj golova koje je tim ostvario u svim odigranim utakmicama.
    int goalDiff = 0; // Gol razlika (broj postignutih golova - broj primljenih golova) u svim odigranim utakmicama.
};

// Lista timova.
Team teams[MAXT];

// Ostvareni poeni u medjusobnim mecevima izmedju timova.
// Npr. gameScores[1][4] daje koliki je rezultat tim 1 ostvario protiv tima 4.
int gameScores[MAXT][MAXT];

// Postignuti golovi u medjusobnim mecevima izmedju timova prilikom gostovanja.
// Npr. guestGameGoals[1][4] daje koliko je golova tim 1 dao timu 4 na terenu tima 4.
int guestGameGoals[MAXT][MAXT];

// Funkcija koja uporedjuje timove po kriterijima i vraca naredne vrijednosti:
// 1 - ako t1 treba biti ispred t2
// 2 - ako t2 treba biti ispred t1
// 0 - ako t1 i t2 imaju identican rezultat
int compare(const Team &t1, const Team &t2) {

    // Kriterij 1: Ako su rezultati razliciti.
    if(t1.score != t2.score) {

        if(t1.score > t2.score) {
            return 1;
        } else {
            return 2;
        }
        
    }

    // Kriterij 2: Ako je gol razlika razlicita.
    if(t1.goalDiff != t2.goalDiff) {

        if(t1.goalDiff > t2.goalDiff) {
            return 1;
        } else {
            return 2;
        }

    }

    // Kriterij 3: Ako je ukupan broj postignutih golova razlicit.
    if(t1.goals != t2.goals) {

        if(t1.goals > t2.goals) {
            return 1;
        } else {
            return 2;
        }

    }

    // Rezultat koji je t1 postigao u mecevima protiv t2.
    int t1score = gameScores[t1.index][t2.index];

    // Rezultat koji je t2 postigao u mecevima protiv t1.
    int t2score = gameScores[t2.index][t1.index];

    // Kriterij 4: Ako su postignuti rezultati u medjusobnim mecevima razliciti.
    if (t1score != t2score) {

        if(t1score > t2score) {
            return 1;
        } else {
            return 2;
        }

    }

    // Ukupan broj golova koje je t1 postigao protiv t2 na terenu t2.
    int t1goals = guestGameGoals[t1.index][t2.index];

    // Ukupan broj golova koje je t2 postigao protiv t1 na terenu t1.
    int t2goals = guestGameGoals[t2.index][t1.index];

    // Kriterij 5: Ako je broj postignutih golova u gostujicim mecevima razlicit.
    if(t1goals != t2goals) {

        if(t1goals > t2goals) {
            return 1;
        } else {
            return 2;
        }

    }

    // Nije moguce odrediti poredak / potrebno je razigravanje.
    return 0;
}

// Specificni comparator koji poredi dva tima na bazi svih parametara.
bool comparator(const Team &t1, const Team &t2) {

    // Uporedimo t1 i t2.
    int compareResult = compare(t1, t2);

    // Vracamo true ako t1 treba biti ispred t2, u suprotnom false.
    return compareResult == 1;

}

static void solve() {

    cin >> T;

    // Indeks koji koristimo da mozemo iz imena dobiti indeks tima.
    unordered_map<string, int> dict;

    // Ucitavamo nazive timova.
    string name;
    for(int i = 0; i < T; i++) {
        cin >> name;

        // Spasavamo relaciju izmedju naziva tima i rednog broja tima radi lakseg pronalazenja tima.
        dict[name] = i;
        
        // Iste podatke spasavamo na samom timu radi lakseg ispisa rezultata.
        teams[i].name = name;
        teams[i].index = i;
    }

    // Resetujemo sve medjusobne rezultate na 0.
    for(int r = 0; r < T; r++) {
        for(int c = 0; c < T; c++) {
            gameScores[r][c] = 0;
            guestGameGoals[r][c] = 0;
        }
    }

    cin >> U;

    string t1name; // Naziv prvog (domaceg) tima).
    string t2name; // Naziv drugog (gostujuceg) tima.
    char separator; // Separator (-,:)
    int t1goals; // Broj golova koje je postigao prvi tim.
    int t2goals; // Broj golova koje je postigao drugi tim.

    // Ucitavamo rezultate utakmica.
    for(int i = 0; i < U; i++) {

        cin >> t1name >> separator >> t2name >> separator >> t1goals >> separator >> t2goals;

        // Dobijamo indekse timova na bazi imena.
        int t1i = dict[t1name];
        int t2i = dict[t2name];

        // Pravimo reference na timove.
        Team &t1 = teams[t1i];
        Team &t2 = teams[t2i];

        // Racunamo gol razlike za svaki tim.
        t1.goalDiff += t1goals - t2goals;
        t2.goalDiff += t2goals - t1goals;

        // Povecavamo ukupan broj golova za oba tima.
        t1.goals += t1goals;
        t2.goals += t2goals;

        // Povecavamo broj postignutih golova tima t2 protiv tima t1 u gostovanju.
        guestGameGoals[t2i][t1i] += t2goals;

        // IF: Ako je prvi tim postigao vise golova.
        if(t1goals > t2goals) {

            // Prvi tim dobija +3 poena ukupno.
            t1.score += 3;
            // Prvi tim dobija +3 poena u mecevima protiv drugog tima.
            gameScores[t1i][t2i] += 3;

        } else {

            // IF: Ako je drugi tim pobijedio.
            if(t2goals > t1goals) {

                // Drugi tim dobija +3 poena ukupno.
                t2.score += 3;
                // Drugi tim dobija +3 poena u mecevima protiv prvog tima.
                gameScores[t2i][t1i] += 3;

            } else { // ELSE: Izjednaceno.

                // Oba tima dobijaju +1 poen ukupno.
                t1.score++;
                t2.score++;

                // Oba tima dobijaju +1 poen u medjusobnim mecevima.
                gameScores[t1i][t2i] += 1;
                gameScores[t2i][t1i] += 1;
            }
        }

    }

    // Sortiramo timove najbolje sto mozemo.
    sort(teams, teams+T, comparator);

    // Pretpostavimo da je poredak odredjen sortiranjem.
    bool undetermined = false;

    // Posto su sada svi timovi sortirani, poredimo susjedne timove na listi da vidimo
    // da li su u potpunosti izjednaceni odnosno da li treba razigravanje.
    for(int i = 0; i < T-1; i++) {

        // Referencirajmo dva susjedna tima na rang listi.
        const Team &t1 = teams[i];
        const Team &t2 = teams[i+1];

        // Uporedimo rezultat oba tima.
        int compareResult = compare(t1, t2);

        // IF: Ako t1 i t2 imaju identican rezultat.
        if(compareResult == 0) {
            // Potrebno je razigravanje.
            undetermined = true;
            break;
        }
    }

    // IF: Ako je poredak neodredjen.
    if(undetermined) {
        cout << "Potrebno je razigravanje!" << '\n';
    } else {
        // Ispisemo timove i rezultate.
        for(int i = 0; i < T; i++) {
            cout << teams[i].name << ' ' << teams[i].score << '\n';
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
