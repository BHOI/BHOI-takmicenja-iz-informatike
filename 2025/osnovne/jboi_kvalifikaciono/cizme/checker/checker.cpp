#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> simulate(vector<int>& stanje, vector<int>& potezi) {
    vector <int> bad;
    vector <int> v = stanje;
    int n = v.size();
    int m = potezi.size();
    
    for(auto p : potezi) {
        p--;
        if(p < 0 || p >= n - 1) return bad; // Out of bounds
        if(v[p] == 0) return bad; // Cannot move empty space
        if(v[p] == 1) {
            if(p == 0) return bad; // Cannot move left from the first position 
            if(v[p - 1] == 0) {
                swap(v[p], v[p - 1]);
                continue;
            }
            if(p == 1) return bad;
            if(v[p - 2] == 0) {
                swap(v[p], v[p - 2]);
                continue;
            }
            return bad; // Cannot move left
        }
        if(v[p] == 2) {
            if(p == n - 1) return bad; // Cannot move right from the last position
            if(v[p + 1] == 0) {
                swap(v[p], v[p + 1]);
                continue;
            }
            if(p == n - 2) return bad;
            if(v[p + 2] == 0) {
                swap(v[p], v[p + 2]);
                continue;
            }
            return bad; // Cannot move right
        }
    }

    return v;
}

bool verify(vector<int> v) {
    if (v.empty()) return false; // Empty vector is not valid
    // Verify vector goes 1, 1, 1, ..., 1, 0, 0, ..., 0, 2, 2, ..., 2
    int i = 0;
    while(v[i] == 1 && i < v.size()) i++;
    while(v[i] == 0 && i < v.size()) i++;
    while(v[i] == 2 && i < v.size()) i++;
    return i == v.size();
}

int main(int argc, char* argv[])
{
    // OBAVEZNO JE KOMPAJLIRATI CHECKER SA PARAMETROM -static !!!
    // Autor zadatka na sistem predaje executable file
    ifstream input(argv[1]);  // Ulazni podaci zadatka
    ifstream correct_output(argv[2]); // Izlazna podaci zadatka(iako se ne koriste neka stoje barem prazne datoteke)
    ifstream contestant_output(argv[3]); // Takmicarov izlaz

    /*
        Checker funkcionise na taj nacin sto koristi CMS-ov tzv. standard manager output

        Na standardni output potrebno je ispisati u obliku stringa decimalni broj
        koji predstavlja procenat bodova koji je takmicar osvojio za dati zadatak,
        za 100% tacno ispis je "1.0", za 0% je "0.0"

        Dodatno, na error izlaz potrebno je ispisati neki od stringova:
        "translate:success", "translate:partial", "translate:wrong"

        Primjer: Takmicarovo rjesenje je 65.42% tacno
        cout << "0.6542" << endl;
        cerr << "translate:partial" << endl;
    
    */

    // Read the input
    int n;
    input >> n;
    vector<int> stanje(n);
    for (int i = 0; i < n; i++) {
        input >> stanje[i];
    }

    // Read the correct output
    int min_br_poteza;
    correct_output >> min_br_poteza;

    // Verify contestant_output is of the right form:
    // One number (length of array), then whitespace, then array elements
    int length;
    contestant_output >> length;

    // Check if reading length failed
    if (contestant_output.fail()) {
        cout << "0.0" << endl;
        cerr << "translate:wrong" << endl;
        return 1;
    }

    vector<int> output(length);
    for (int i = 0; i < length; i++) {
        contestant_output >> output[i];
        
        // Check if reading the integer failed
        if (contestant_output.fail()) {
            cout << "0.0" << endl;
            cerr << "translate:wrong" << endl;
            return 1;
        }
    }

    // Check if there are any extra characters/numbers after reading all expected values
    string extra;
    if (contestant_output >> extra) {
        // If we can read something more, there's extra content
        cout << "0.0" << endl;
        cerr << "translate:wrong" << endl;
        return 1;
    }

    // Additional check: verify we're at EOF and no errors occurred
    if (!contestant_output.eof()) {
        cout << "0.0" << endl;
        cerr << "translate:wrong" << endl;
        return 1;
    }

    if(min_br_poteza == length) {
        // Ili 1.0 ili 0.0
        vector <int> rez = simulate(stanje, output);
        if (rez.size() != length) {
            cout << "0.0" << endl;
            cerr << "translate:wrong" << endl;
            return 1;
        }
        bool ok = verify(rez);
        if (!ok) {
            cout << "0.0" << endl;
            cerr << "translate:wrong" << endl;
            return 1;
        }
        cout << "1.0" << endl;
        cerr << "translate:success" << endl;
    }
    else {
        // Ili 0.2 ili 0.0
        vector <int> rez = simulate(stanje, output);
        bool ok = verify(rez);
        if (!ok) {
            cout << "0.0" << endl;
            cerr << "translate:wrong" << endl;
            return 1;
        }
        cout << "0.2" << endl;
        cerr << "translate:partial" << endl;
    }

    return 0;
}