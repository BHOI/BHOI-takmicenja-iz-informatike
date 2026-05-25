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

    cout << zamjene_1 << endl;

    return 0;
}
