#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    int posljednje_polje = 0;
    vector<int> A(n), B(n), D(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> D[i];
        posljednje_polje = max(posljednje_polje, B[i]);
    }

    cout << posljednje_polje - 999 << " " << posljednje_polje << endl;

    return 0;
}
