#include "testlib.h"
#include <fstream>
#include <string>
#include <assert.h>
#include <sstream>

#define main __main
#include "main.cpp"

void testInit(int argc, char** argv) {
    registerGen(argc, argv, 1);
}

#define BALANSIRANI_MECEVI          0b0001
#define POBJEDA_GOSTIJU             0b0010
#define POBJEDA_DOMACIH             0b0100
#define ISTI_BODOVI                 0b1000

#define SVE_NASUMICNO              -2
#define NISU_ISTI_BODOVI           -1
#define ISTI_BODOVI_GOL_RAZLIKA     0
#define ISTI_BODOVI_VISE_GOLOVA     1
#define ISTI_BODOVI_DIREKTNI_MECEVI 2
#define ISTI_BODOVI_GOSTUJUCI       3
#define ISTI_BODOVI_RAZIGRAVANJE    4

// MAX 0b1001111

#define MAXT 100
#define MAXU 200
int MAXG;

Mec generisiMec(bool pobjedaDomacih, bool pobjedaGostiju, const Tim& a, const Tim& b) {
    Mec m;
    m.domaci = a.ime;
    m.gostujuci = b.ime;
    if (pobjedaGostiju && pobjedaDomacih) {
        m.domaciGolovi = rnd.next(0, MAXG);
        m.gostujuciGolovi = rnd.next(0, MAXG);
    } else if (pobjedaGostiju && !pobjedaDomacih) {
        m.domaciGolovi = rnd.next(0, MAXG);
        m.gostujuciGolovi = m.domaciGolovi + rnd.next(1, MAXG);
    } else if (!pobjedaGostiju && pobjedaDomacih) {
        m.gostujuciGolovi = rnd.next(0, MAXG);
        m.domaciGolovi = m.gostujuciGolovi + rnd.next(1, MAXG);
    } else {
        m.domaciGolovi = rnd.next(0, MAXG);
        m.gostujuciGolovi = m.domaciGolovi;
    }
    return m;
}

Mec generisiMec(bool pobjedaDomacih, bool pobjedaGostiju, const vector<Tim>& timovi) {
    int idxA = rnd.next(0, (int)timovi.size() - 1);
    int idxB = (idxA + rnd.next(1, (int)timovi.size() - 2)) % timovi.size();
    return generisiMec(pobjedaDomacih, pobjedaGostiju, timovi[idxA], timovi[idxB]);
}

bool generisiBalansiraneMeceve(bool pobjedaDomacih, bool pobjedaGostiju, const vector<Tim>& timovi, vector<Mec>& mecevi) {
    int t = timovi.size();
    int multiples = t * (t-1);
    int maxMultiplier = (MAXU-1) / multiples;
    if (maxMultiplier == 0) { return false; }
    int multiplier = rnd.next(1, maxMultiplier);
    for (int r=0; r<multiplier; r++)
        for (int i=0; i<t; i++)
            for (int j=0; j<t; j++)
                if (i != j)
                    mecevi.push_back(generisiMec(pobjedaDomacih, pobjedaGostiju, timovi[i], timovi[j]));
    return true;
}

int detektujVrstuIstihBodova(const Tim& a, const Tim& b) {
    if (a.potrebnoRazigravanje(b)) {
        return ISTI_BODOVI_RAZIGRAVANJE;
    } else if (a.mozeSePoreditiSaGostujucimGolovima(b)) {
        return ISTI_BODOVI_GOSTUJUCI;
    } else if (a.mozeSePoreditiSaDirektnimMecom(b)) {
        return ISTI_BODOVI_DIREKTNI_MECEVI;
    } else if (a.mozeSePoreditiSaUkupnoGolova(b)) {
        return ISTI_BODOVI_VISE_GOLOVA;
    } else if (a.mozeSePoreditiSaGolRazlikom(b)) {
        return ISTI_BODOVI_GOL_RAZLIKA;
    } else {
        return NISU_ISTI_BODOVI;
    }
}

// timovi je namjerno kopirano
string testirajMeceve(vector<Tim> timovi, const vector<Mec>& mecevi, int trazenaVrstaZavrsetka) {
    if (trazenaVrstaZavrsetka == SVE_NASUMICNO) return "OK";
    for (const auto& mec : mecevi) {
        aplicirajMec(timovi, mec);
    }
    try {
        sort(timovi.begin(), timovi.end(), &poredi);
        int maxDetektovanaVrsta = NISU_ISTI_BODOVI;
        for (int i=1; i<timovi.size(); i++) {
            int tmp = detektujVrstuIstihBodova(timovi[i-1], timovi[i]);
            if (tmp != -1 && tmp != trazenaVrstaZavrsetka) {
                stringstream ss;
                ss << "Requested type: " << trazenaVrstaZavrsetka << " but got: " << tmp;
                return ss.str();
            }
        }
        return "OK";
    } catch(string err) {
        if (err != "Potrebno je razigravanje!") throw runtime_error(err);
        return (trazenaVrstaZavrsetka == ISTI_BODOVI_RAZIGRAVANJE)
            ? "OK" : "Playoffs requested";
    }
}

struct Parametri {
    bool balansiraniMecevi;
    bool pobjedaDomacih;
    bool pobjedaGostiju;
    int vrstaZavrsetka;
    Parametri(
        bool _balansiraniMecevi,
        bool _pobjedaDomacih,
        bool _pobjedaGostiju,
        int _vrstaZavrsetka
    ) : balansiraniMecevi(_balansiraniMecevi),
    pobjedaDomacih(_pobjedaDomacih),
    pobjedaGostiju(_pobjedaGostiju),
    vrstaZavrsetka(_vrstaZavrsetka) {}
};

vector<Parametri> parametri = {
    Parametri(true, true, true, 0),
    Parametri(true, true, false, 0),
    Parametri(true, false, true, 0),
    Parametri(false, true, true, 0),
    Parametri(false, true, false, 0),
    Parametri(false, false, true, 0),
    Parametri(true, true, true, 1),
    Parametri(true, true, false, 1),
    Parametri(true, false, true, 1),
    Parametri(true, false, false, 1),
    Parametri(false, true, true, 1),
    Parametri(false, true, false, 1),
    Parametri(false, false, true, 1),
    Parametri(false, false, false, 1),
    Parametri(true, true, true, 2),
    Parametri(true, true, false, 2),
    Parametri(true, false, true, 2),
    Parametri(true, false, false, 2),
    Parametri(false, true, true, 2),
    Parametri(false, true, false, 2),
    Parametri(false, false, true, 2),
    Parametri(false, false, false, 2),
    Parametri(true, true, true, 3),
    Parametri(false, true, true, 3),
    Parametri(false, true, false, 3),
    Parametri(false, false, true, 3),
    Parametri(false, false, false, 3),
    Parametri(true, true, true, 4),
    Parametri(false, true, true, 4),
    Parametri(false, true, false, 4),
    Parametri(false, false, true, 4),
    Parametri(false, false, false, 4),
    Parametri(true, true, true, -1),
    Parametri(false, true, true, -1),
    Parametri(false, true, false, -1),
    Parametri(false, false, true, -1),
    Parametri(false, false, false, -1),
    Parametri(true, true, true, -2),
    Parametri(true, true, false, -2),
    Parametri(true, false, true, -2),
    Parametri(true, false, false, -2),
    Parametri(false, true, true, -2),
    Parametri(false, true, false, -2),
    Parametri(false, false, true, -2),
    Parametri(false, false, false, -2),
    // total: 45
};

// golovi nisu nasumicni = pobjedaDomacih = false || pobjedaGostiju = false
// uvijek nerijeseno = pobjedaDomacih = false && pobjedaGostiju = false
// NEMOGUCE SITUACIJE:
// Uvijek nerijeseno, isti skor na gol razliku
// Balansirani mecevi, golovi nisu nasumicni, bez razlicitih bodova na kraju
// Balansirani mecevi, golovi nisu nasumicni, isti skor na gostujuce bodove
// Balansirani mecevi, golovi nisu nasumicni, razigravanje

void makeTest(std::ofstream& inputFile, int subtask, int testcase, float testPercent) {
    assert(subtask < parametri.size());
    Parametri p = parametri[subtask];

    MAXG = 10;

    cout << "Match balance: " << p.balansiraniMecevi;
    cout << "\tHome win: " << p.pobjedaDomacih;
    cout << "\tAway win: " << p.pobjedaGostiju;
    cout << "\tEnd type: " << p.vrstaZavrsetka << endl;

    int retries = 0;

    while(true) {
        int t = rnd.next(3, MAXT - 1);
        int u = rnd.next(3, MAXU - 1);
        set<string> imena;
        while(imena.size() < t)
            imena.insert(rnd.next("[a-z_A-Z]{10}"));
        vector<Tim> timovi;
        for (const auto& ime : imena) {
            Tim t;
            t.ime = ime;
            timovi.push_back(t);
        }
        assert(timovi.size() == t);
        assert(t < MAXT);
        assert(t > 1);

        vector<Mec> mecevi;
        if (p.balansiraniMecevi) {
            if (!generisiBalansiraneMeceve(p.pobjedaDomacih, p.pobjedaGostiju, timovi, mecevi)) {
                // cout << "T was too big for balanced matches: " << t << endl;
                continue;
            }
            u = mecevi.size();
        } else {
            for (int i=0; i<u; i++) {
                mecevi.push_back(generisiMec(p.pobjedaDomacih, p.pobjedaGostiju, timovi));
            }
        }
        assert(u == mecevi.size());
        assert(u < MAXU);
        assert(u > 0);

        string test = testirajMeceve(timovi, mecevi, p.vrstaZavrsetka);
        if (test == "OK") {
            inputFile << t << endl;
            for (int i=0; i<timovi.size(); i++) {
                inputFile << timovi[i].ime;
                if (i != timovi.size() - 1) inputFile << " ";
            }
            inputFile << endl;
            inputFile << u << endl;
            for (const auto& mec: mecevi)
                inputFile << mec << endl;
            break;
        }
        // cout << test << endl;
        retries++;
        if (retries % 1000 == 0 && MAXG > 2) {
            MAXG--;
            cout << "Decreasing maxg to " << MAXG << endl;
        }
    }
}