#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int maxVal = 0;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
        maxVal = max(maxVal, a[i]);
    }

    vector<bool> can(maxVal + 1, false);
    can[0] = true;

    int removable = 0;

    // Procesiramo sortirane razlicite vrijednosti
    for (auto& [val, cnt] : freq) {
        if (can[val]) {
            // Sve kopije su uklonjive
            removable += cnt;
        } else {
            // Bazni element, jedna kopija ostaje
            removable += cnt - 1;
            // Azuriramo DP (coin change)
            for (int v = val; v <= maxVal; v++) {
                can[v] = can[v] || can[v - val];
            }
        }
    }

    cout << removable << endl;
    return 0;
}
