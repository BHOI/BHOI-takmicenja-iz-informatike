#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> v(n);
    int sareni = 0;

    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i] == 2) sareni++;
    }

    // Broj zamjena ako prvo idu sareni klikeri, pa onda jednobojni
    int zamjene_1 = 0;

    for(int i=0;i<sareni;i++) {
        if(v[i] == 1) {
            zamjene_1++;
        }
    }

    // Broj zamjena ako prvo idu jednobojni klikeri, pa onda sareni
    int zamjene_2 = 0;
    for(int i=0;i<n-sareni;i++) {
        if(v[i] == 2) {
            zamjene_2++;
        }
    }

    cout << min(zamjene_1, zamjene_2) << endl;

    return 0;
}
