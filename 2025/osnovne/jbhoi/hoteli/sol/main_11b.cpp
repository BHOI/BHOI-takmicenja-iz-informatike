#include <iostream>

using namespace std;

int k[100010];

int main() {
    int n, m;
    cin >> n >> m;

    int najveci = 0;

    for(int i=0; i < n; i++) {
        cin >> k[i];
        if(k[i] > najveci) {
            najveci = k[i];
        }
    }

    if(najveci >= m) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}