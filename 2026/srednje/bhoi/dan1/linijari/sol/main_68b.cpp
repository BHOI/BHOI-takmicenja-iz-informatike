#include <iostream>
using namespace std;

int main() {
    int n;
    int x;
    cin >> n >> x;

    int niz[100];
    for(int i=0;i<n;i++){
        cin >> niz[i];
    }

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += niz[i];
    }

    cout << (sum >= x ? "DA" : "NE") << "\n";

    return 0;
}
