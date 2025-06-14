#include <iostream>

using namespace std;

int k[100010];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i < n; i++) {
        cin >> k[i];
    }

    int min_udaljenost = n;

    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            int suma = 0;
            for(int i=start; i <= end; i++) {
                suma += k[i];
            }
            if(suma >= m) {
                int udaljenost = end - start;
                if(udaljenost < min_udaljenost) {
                    min_udaljenost = udaljenost;
                }
            }
        }
    }

    cout << min_udaljenost << endl;

    return 0;
}