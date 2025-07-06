// Jedan od ciljeva je skroz izbjeci operacije sa decimalnim brojevima.
// Najlaksi nacin za to je prvo unijeti broj kao float/double a zatim ga
// pomnoziti sa 100 i pretvoriti u int sa funkcijom round().

// Drugi kacin kako to mozemo uraditi je tako sto unesemo cijeli i
// decimalni dio odvojeno i iskoristimo cinjenicu da su cijene uvijek
// date sa 2 decimalna mjesta.
// Ako bismo pomnozili cijeli dio sa 100 i sabrali decimalni dio (unesen
// kao obicni int), dobit cemo uvijek cijeli broj s kojim mozemo bez
// problema raditi. Na primjer, cijena 5.67 ce postati broj
// 5 * 100 + 67 = 567.

// Za 100% bodova potrebno je koristiti dinamicko programiranje sa
// algoritmom coin change.

#ifndef GENERATOR
#include <math.h>
#include <iostream>
#include <assert.h>
#include <sstream>
using namespace std;

int kovanice[1000];

// unosi jedan decimalni broj kao integer
int unesi_cijenu() {
    string broj;
    cin >> broj;

    // prvi nacin: unijeti dva cijela broja sa scanf,
    // odvojena sa ., zatim ih spojiti
    int cijeli = -1, decimalni = -1;
    sscanf(broj.c_str(), "%d.%d", &cijeli, &decimalni);
    int nacin1 = cijeli*100 + decimalni;

    // drugi nacin: unijeti double a zatim koristiti
    // funkciju round
    stringstream ss(broj);
    double dec_broj;
    ss >> dec_broj;
    int nacin2 = round(dec_broj * 100.0);

    if (nacin1 != nacin2) {
        cerr << nacin1 << " != " << nacin2 << " ...\n";
    }
    assert(nacin1 == nacin2);
    return nacin1;
}

int solve(int n, int* kovanice, int kusur);

int main() {
    int n;
    cin >> n;
    int p, u;
    u = unesi_cijenu();
    p = unesi_cijenu();
    int kusur = u - p;
    for (int i=0; i<n; i++) {
        kovanice[i] = unesi_cijenu();
    }
    int ret = solve(n, kovanice, kusur);
    if (ret < 0) {
        cout << "greska";
    } else {
        cout << ret;
    }
}
#endif

#include <string.h>
int solve(int n, int* kovanice, int kusur) {
    if (kusur == 0) {
        return 0;
    }
    int* rjesenje = new int[kusur + 1];
    memset(rjesenje, 0, sizeof(rjesenje));

    for (int i=0; i<n; i++) {
        // da vratimo kovanice[i] treba nam samo jedna
        // kovanica - tacnije kovanica[i]
        if (kovanice[i] <= kusur) {
            rjesenje[kovanice[i]] = 1;
        } else {
            break;
        }
        // std::cout << kovanice[i] << std::endl;
    }
    // nemamo potrebe kretati od 0 jer je kovanica[0]
    // najmanja kovanica i ne mozemo imati rjesenje
    // manje od te kovanice
    for (int i=kovanice[0]; i<=kusur; i++) {
        for (int j=0; j<n; j++) {
            int rjesenje_idx = i - kovanice[j];
            // ako je ova kovanica veca nego ikakvo
            // rjesenje. Npr ako kusur od 10 pokusavamo
            // vratiti kovanicom od 15.
            if (rjesenje_idx < 0) {
                break;
            }
            // ako s ovom kovanicom ne mozemo doci do
            // trenutnog rjesenja, preskocimo kovanicu
            if (rjesenje[rjesenje_idx] == 0) {
                continue;
            }
            // Ovu kovanicu mozemo iskoristiiti samo ako nas ona vodi
            // do rjesenja sa manje kovanica (pogledati objasnjenje
            // coin change algoritma). 
            if (rjesenje[i] == 0 || rjesenje[rjesenje_idx] + 1 < rjesenje[i]) {
                rjesenje[i] = rjesenje[rjesenje_idx] + 1;
            }
        }
    }
    int ret = (rjesenje[kusur] == 0) ? -1 : rjesenje[kusur];
    // for (int i=1; i<=kusur; i++) {
    //     if (rjesenje[i] != rjesenje[i - 1]) {
    //         std::cout << i << ": " << rjesenje[i] << std::endl;
    //     }
    // }
    delete[] rjesenje;
    return ret;
}