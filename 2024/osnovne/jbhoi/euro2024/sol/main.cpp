#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

// #define ISPIS_STATISTIKE

struct Mec {
    string domaci;
    string gostujuci;
    int domaciGolovi = 0;
    int gostujuciGolovi = 0;
};

istream& operator>>(istream& in, Mec& mec) {
    string tmp;
    in >> mec.domaci >> tmp >> mec.gostujuci >> tmp >> mec.domaciGolovi >> tmp >> mec.gostujuciGolovi;
    return in;
}

ostream& operator<<(ostream& out, const Mec& mec) {
    out << mec.domaci << " - " << mec.gostujuci << " : " << mec.domaciGolovi << " - " << mec.gostujuciGolovi;
    return out;
}

struct Tim {
    string ime;
    int bodovi = 0;
    int golovaKaoGost = 0;
    int golovaKaoDomacin = 0;
    int golRazlika = 0;
    map<string, int> bodovaProtivTima;

    bool porediSaBodovima(const Tim& drugi) const {
        return bodovi > drugi.bodovi;
    }

    // U slučaju izjednačenja po bodovima tim sa boljom tzv. "gol razlikom" ima
    // prednost. Gol razlika je razlika ukupnog broja zabijenih i primljenih
    // golova u svim utakmicama do sada. Dakle ako je tim `X` igrao **2**
    // utakmice, gdje je prvu pobjedio **3-1**, a drugu izgubio **4-0** njegova
    // gol razlika je **-2** (manja je od 0).
    bool mozeSePoreditiSaGolRazlikom(const Tim& drugi) const {
        return drugi.bodovi == bodovi;
    }

    bool porediSaGolRazlikom(const Tim& drugi) const {
        return golRazlika > drugi.golRazlika;
    }

    // U slučaju izjednačenja i po tom kriteriju prednost ima tim koji je više
    // golova zabio ukupno. Ako timovi **X** i **Y** oba imaju isto bodova i
    // istu gol razliku, ali tim **X** je ukupno zabio 13 golova i primio 10,
    // dok je tim **Y** zabio 11 golova i primio 8 onda tim **X** ima prednost.
    bool mozeSePoreditiSaUkupnoGolova(const Tim& drugi) const {
        return mozeSePoreditiSaGolRazlikom(drugi) && golRazlika == drugi.golRazlika;
    }

    bool porediSaUkupnoGolova(const Tim& drugi) const {
        return ukupnoGolova() > drugi.ukupnoGolova();
    }

    // U slučaju izjednačenja i po tom kriteriju posmatraju se utakmice
    // direktno između ta 2 tima (ako postoje). Tim koji je stekao više bodova
    // u direktnim utakmicama između ta dva tima ima prednost.
    bool mozeSePoreditiSaDirektnimMecom(const Tim& drugi) const {
        return mozeSePoreditiSaUkupnoGolova(drugi) && ukupnoGolova() == drugi.ukupnoGolova();
    }

    bool porediSaDirektnimMecom(const Tim& drugi) const {
        return const_cast<map<string, int>&>(bodovaProtivTima)[drugi.ime] >
               const_cast<Tim&>(drugi).bodovaProtivTima[drugi.ime];
    }

    // U slučaju izjednačenja i po tom kriteriju prednost ima tim koji je više
    // golova zabio u domaćem stadionu suprotnog tima (dakle "u gostima").
    bool mozeSePoreditiSaGostujucimGolovima(const Tim& drugi) const {
        return mozeSePoreditiSaDirektnimMecom(drugi) &&
            const_cast<map<string, int>&>(bodovaProtivTima)[drugi.ime] ==
            const_cast<Tim&>(drugi).bodovaProtivTima[drugi.ime];
    }

    bool porediSaGostujucimGolovima(const Tim& drugi) const {
        return golovaKaoGost > drugi.golovaKaoGost;
    }

    // U slučaju da su dva tima izjednačena po svim ovim kriterijima potrebno
    // je da timovi odigraju direktnu utakmicu između ovih timova.
    bool potrebnoRazigravanje(const Tim& drugi) const {
        return mozeSePoreditiSaGostujucimGolovima(drugi) && golovaKaoGost == drugi.golovaKaoGost;
    }

    int ukupnoGolova() const { return golovaKaoGost + golovaKaoDomacin; }
};

ostream& operator<<(ostream& out, const Tim& tim) {
    out << "| " << tim.ime << " | " << tim.bodovi << " | " << tim.golRazlika << " | " <<
                   tim.golovaKaoDomacin << " | " << tim.golovaKaoGost << " | " << tim.ukupnoGolova() << " |";
    return out;
}

Tim& nadjiTim(vector<Tim>& timovi, string ime) {
    for (auto& tim : timovi) {
        if (tim.ime == ime) {
            return tim;
        }
    }
    throw runtime_error("Ne postoji tim sa ovim imenom");
}

bool poredi(const Tim& a, const Tim& b) {
    if (a.potrebnoRazigravanje(b)) {
        throw string("Potrebno je razigravanje!");
    } else if (a.mozeSePoreditiSaGostujucimGolovima(b)) {
        return a.porediSaGostujucimGolovima(b);
    } else if (a.mozeSePoreditiSaDirektnimMecom(b)) {
        return a.porediSaDirektnimMecom(b);
    } else if (a.mozeSePoreditiSaUkupnoGolova(b)) {
        return a.porediSaUkupnoGolova(b);
    } else if (a.mozeSePoreditiSaGolRazlikom(b)) {
        return a.porediSaGolRazlikom(b);
    } else {
        return a.porediSaBodovima(b);
    }
}

void aplicirajMec(vector<Tim>& timovi, const Mec& mec) {
    Tim& domaci = nadjiTim(timovi, mec.domaci);
    Tim& gostujuci = nadjiTim(timovi, mec.gostujuci);
    int bodoviDomacim = 0;
    int bodoviGostima = 0;
    if (mec.domaciGolovi == mec.gostujuciGolovi) {
        bodoviDomacim = 1;
        bodoviGostima = 1;
    } else if (mec.domaciGolovi > mec.gostujuciGolovi) {
        bodoviDomacim = 3;
        bodoviGostima = 0;
    } else {
        bodoviDomacim = 0;
        bodoviGostima = 3;
    }
    domaci.bodovi += bodoviDomacim;
    gostujuci.bodovi += bodoviGostima;
    domaci.golovaKaoDomacin += mec.domaciGolovi;
    gostujuci.golovaKaoGost += mec.gostujuciGolovi;
    domaci.golRazlika += mec.domaciGolovi - mec.gostujuciGolovi;
    gostujuci.golRazlika += mec.gostujuciGolovi - mec.domaciGolovi;
    domaci.bodovaProtivTima[gostujuci.ime] += bodoviDomacim;
    gostujuci.bodovaProtivTima[domaci.ime] += bodoviGostima;
}

int main()
{
    int t, u;
    vector<Tim> timovi;
    cin >> t;
    for (int i=0; i<t; i++) {
        Tim t;
        cin >> t.ime;
        timovi.push_back(t);
    }
    cin >> u;
    try {
        for (int i=0; i<u; i++) {
            Mec m;
            cin >> m;
            aplicirajMec(timovi, m);
        }
        sort(timovi.begin(), timovi.end(), &poredi);
        for (const Tim& t : timovi) {
            cout << t.ime << " " << t.bodovi << endl;
        }
    } catch(string err) {
        cout << err << endl;
    }
#ifdef ISPIS_STATISTIKE
    cout << "| Ime | Bodovi | Gol razlika | Golovi na domacem terenu | Golovi na gostujucem terenu | Ukupno golova |\n";
    cout << "|-----|--------|-------------|--------------------------|-----------------------------|---------------|\n";
    for (const auto& tim : timovi) {
        cout << tim << endl;
    }
#endif
    return 0;
}