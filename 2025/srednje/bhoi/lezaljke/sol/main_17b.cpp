#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, q, l, h;
    
    cin >> n;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cin >> q >> l >> h;

    int a, b;
    cin >> a >> b;

    float udaljenost;
    udaljenost = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if(udaljenost >= l && udaljenost <= h) {
        cout << "DA" << endl;
    } else {
        cout << "NE" << endl;
    }

    return 0;
}