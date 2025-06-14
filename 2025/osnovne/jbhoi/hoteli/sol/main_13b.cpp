#include <iostream>

using namespace std;

int k[100010];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i < n; i++) {
        cin >> k[i];
    }

    int min_udaljenost = 10;

    // Isprobati sve kombinacije hotela 
    for(int i=0;i<(1<<n);i++) {
        int suma = 0;
        for(int j=0;j<n;j++) {
            if(i & (1<<j)) {
                suma += k[j];
            }
        }
        
        int prvi = 10, posljednji = 0;
        for(int j=0;j<n;j++) {
            if(i & (1<<j)) {
                if(j < prvi) {
                    prvi = j;
                }
                if(j > posljednji) {
                    posljednji = j;
                }
            }
        }

        if(suma >= m && posljednji - prvi < min_udaljenost) {
            min_udaljenost = posljednji - prvi;
        }
    }

    cout << min_udaljenost << endl;

    return 0;
}