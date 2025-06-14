#include <iostream>

using namespace std;

int k[100010];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i < n; i++) {
        cin >> k[i];
    }

    cout << (m-1) / 100 << endl;

    return 0;
}