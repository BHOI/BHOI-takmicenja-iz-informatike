#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // OBAVEZNO JE KOMPAJLIRATI CHECKER SA PARAMETROM -static !!!
    // Autor zadatka na sistem predaje executable file
    ifstream input(argv[0]);  // Ulazni podaci zadatka
    ifstream correct_output(argv[1]); // Izlazna podaci zadatka(iako se ne koriste neka stoje barem prazne datoteke)
    ifstream contestant_output(argv[2]); // Takmicarov izlaz

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

    cout << "0.6542" << endl;
    cerr << "translate:partial" << endl;

    return 0;
}