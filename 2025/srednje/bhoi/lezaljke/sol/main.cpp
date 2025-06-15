#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, l, h;
    
    cin >> n;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    cin >> q >> l >> h;

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        int kvadrat_udaljenosti = (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
        if (kvadrat_udaljenosti >= l * l && kvadrat_udaljenosti <= h * h) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    }

    return 0;
}