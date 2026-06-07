#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    // ST2: l=1, A_i=B_i -- svaki suncobran pokriva tacno jedno polje
    // Saberi debljine suncobrana po polju, nadji polje s maksimalnom zastitom
    vector<int> prot(100001, 0);
    for (int i = 0; i < n; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        prot[a] += d;
    }

    int best = 1;
    for (int x = 2; x <= 100000; x++) {
        if (prot[x] > prot[best]) {
            best = x;
        }
    }

    cout << best << " " << best << endl;

    return 0;
}
