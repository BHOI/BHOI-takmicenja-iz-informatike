#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// Rjesenje za podzadatak 2 (N <= 20): DP coin change
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }

    if (n > 20) {
        cout << 0 << endl;
        return 0;
    }

    map<int, int> freq;
    for (int x : a) freq[x]++;

    vector<bool> can(maxVal + 1, false);
    can[0] = true;

    int removable = 0;
    for (auto& [val, cnt] : freq) {
        if (can[val]) {
            removable += cnt;
        } else {
            removable += cnt - 1;
            for (int v = val; v <= maxVal; v++) {
                can[v] = can[v] || can[v - val];
            }
        }
    }

    cout << removable << endl;
    return 0;
}
