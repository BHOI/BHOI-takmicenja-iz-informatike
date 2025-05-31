#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Voznja {
    int idVozila;
    int idStanice;
    int sati;
    int minuta;
};

struct Kontrola {
    int idRevizora;
    int idVozila;
    int idStanice;
    int sati;
    int minuta;
    bool jeGreska;
};

struct Revizor {
    vector<Kontrola> kontrole;
};

void nadjiGreske(int v, int n, int m, int s, vector<Voznja> &voz, vector<Revizor> &rev);
void prikaziGreske(vector<Revizor> &r);
bool nemaVozila(Kontrola &k, vector<Voznja> &voz);
bool viseRevizora(Kontrola &k, vector<Revizor> &rev);
bool nemogucaStanica(vector<Voznja> &voz, Kontrola &k, Revizor &rev);
bool nemoguceVozilo(vector<Voznja> &voz, Kontrola &k, Revizor &rev);
bool equals(Kontrola& s1, Kontrola& s2);

int main() {
    /*string testni = "1";

    ifstream in;
    in.open(("testni/ulaz" + testni + ".in").c_str());*/

    int v, n, m, s;
    cin >> v >> n >> m >> s;

    vector<Voznja> voznje;
    for (int i = 0; i < n; i++) {
        Voznja v;

        cin >> v.idVozila >> v.idStanice >> v.sati >> v.minuta;

        voznje.push_back(v);
    }

    vector<Revizor> revizori;
    for (int i = 0; i < m; i++) {
        int r;
        cin >> r;

        Revizor rev;
        for (int j = 0; j < r; j++) {
            Kontrola k;

            cin >> k.idRevizora >> k.idVozila >> k.idStanice >> k.sati >> k.minuta;
            k.jeGreska = false;

            rev.kontrole.push_back(k);
        }

        revizori.push_back(rev);
    }

    nadjiGreske(v, n, m, s, voznje, revizori);

    prikaziGreske(revizori);
}

void nadjiGreske(int v, int n, int m, int s, vector<Voznja> &voz, vector<Revizor> &rev) {
    vector<Kontrola> greske;

    for (int i = 0; i < rev.size(); i++) {
        for (int j = 0; j < rev[i].kontrole.size(); j++) {
            // ID revizora ne valja
            if (rev[i].kontrole[j].idRevizora != i + 1) {
                rev[i].kontrole[j].jeGreska = true;
            }
            // Vozilo ne postoji
            else if (rev[i].kontrole[j].idVozila > v) {
                rev[i].kontrole[j].jeGreska = true;
            }
            // Stanica ne postoji
            else if (rev[i].kontrole[j].idStanice > n) {
                rev[i].kontrole[j].jeGreska = true;
            }
            // Vrijeme ne valja
            else if (rev[i].kontrole[j].sati > 23 || rev[i].kontrole[j].minuta > 59) {
                rev[i].kontrole[j].jeGreska = true;
            }
            // Nema tog vozila u to vrijeme na toj lokaciji
            else if (nemaVozila(rev[i].kontrole[j], voz)) {
                rev[i].kontrole[j].jeGreska = true;
            }
            // Vise revizora na jednoj stanici
            else if (viseRevizora(rev[i].kontrole[j], rev)) {
                rev[i].kontrole[j].jeGreska = true;
            }
            // Grupa revizora nije mogla uci u to vozilo, jer se nije to nalazila posljednji put
            else if (nemogucaStanica(voz, rev[i].kontrole[j], rev[i])) {
                rev[i].kontrole[j].jeGreska = true;
            }
            // Grupa revizora nije mogla uci u to vozilo, jer se trenutno nalazi u drugom vozilu
            else if (nemoguceVozilo(voz, rev[i].kontrole[j], rev[i])) {
                rev[i].kontrole[j].jeGreska = true;
            }

        }
    }
}

void prikaziGreske(vector<Revizor> &r) {
    bool nemaGresaka = true;

    for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[i].kontrole.size(); j++) {
            if (r[i].kontrole[j].jeGreska) {
                nemaGresaka = false;
                Kontrola* k = &r[i].kontrole[j];
                cout << k->idRevizora << " " << k->idVozila << " " << k->idStanice << " " << k->sati << " " << k->minuta << endl;
            }

        }
    }

    if (nemaGresaka) {
        cout << 0 << endl;
    }
}

bool nemaVozila(Kontrola &k, vector<Voznja> &voz) {
    for (int i = 0; i < voz.size(); i++) {
        // Isto vozilo, ista stanica i isto vrijeme
        if (k.idVozila == voz[i].idVozila && k.idStanice == voz[i].idStanice &&
        k.sati == voz[i].sati && k.minuta == voz[i].minuta) {
            return false;
        }
    }

    return true;
}

bool viseRevizora(Kontrola &k, vector<Revizor> &rev) {
    for (int i = 0; i < rev.size(); i++) {
        // Preskoci revizora koji je dat vec
        if (k.idRevizora != i + 1) {
            for (int j = 0; j < rev[i].kontrole.size(); j++) {
                // Isto vozilo, isto vrijeme i ista lokacija
                if (k.idVozila == rev[i].kontrole[j].idVozila && k.sati == rev[i].kontrole[j].sati &&
                k.minuta == rev[i].kontrole[j].minuta && k.idStanice == rev[i].kontrole[j].idStanice) {
                        return true;
                }
            }
        }
    }

    return false;
}

bool equals(Kontrola& s1, Kontrola& s2) {
    if (s1.idStanice == s2.idStanice && s1.idRevizora == s2.idRevizora &&
    s1.idVozila == s2.idVozila && s1.sati == s2.sati && s1.minuta == s2.minuta) {
            return true;
    }
    return false;
}

Voznja& sljedecaStanica(Kontrola &k, vector<Voznja> &voz) {
    for (int i = 0; i < voz.size(); i++) {
        if (voz[i].idStanice == k.idStanice && voz[i].idVozila == k.idVozila &&
        voz[i].sati == k.sati && voz[i].minuta == k.minuta) {
            if (voz[i + 1].idVozila == voz[i].idVozila) {
                return voz[i + 1];
            } else {
                cout << "Los testni primjer" << endl;
                Voznja v;
                return v;
            }
        }
    }
}

bool nemogucaStanica(vector<Voznja> &voz, Kontrola &k, Revizor &rev) {
    int stanica = -1;

    for (int i = 0; i < rev.kontrole.size(); i++) {
        // Greske su izolovane
        if (!rev.kontrole[i].jeGreska) {
            if (equals(k, rev.kontrole[i])) {
                // Ukoliko je predvidjena stanica ista ili je prva onda je okay
                if (stanica == k.idStanice || stanica == -1) {
                    return false;
                } else {
                    return true;
                }
            } else {
                stanica = sljedecaStanica(rev.kontrole[i], voz).idStanice;
            }
        }
    }

    cout << "Los testni primjer" << endl;
    return false;
}

bool nemoguceVozilo(vector<Voznja> &voz, Kontrola &k, Revizor &rev) {
    int sati = -1;
    int minuta = -1;

    for (int i = 0; i < rev.kontrole.size(); i++) {
        // Greske su izolovane
        if (!rev.kontrole[i].jeGreska) {
            if (equals(k, rev.kontrole[i])) {

                if (sati < k.sati || (sati == k.sati && minuta <= k.minuta) || sati == -1) {
                    return false;
                } else {
                    return true;
                }
            } else {
                sati = sljedecaStanica(rev.kontrole[i], voz).sati;
                minuta = sljedecaStanica(rev.kontrole[i], voz).minuta;
            }
        }
    }

    cout << "Los testni primjer" << endl;
    return false;
}
