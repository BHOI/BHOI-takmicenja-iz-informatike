#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Generise sve savrsene kvadrate do n
vector<int> kvadrati(int n) {
    vector<int> kv;
    for (int i = 1; i * i <= n; i++) {
        kv.push_back(i * i);
    }
    return kv;
}

bool moze(int n, int k, const vector<int>& kv) {
    if (k == 1) {
        for (int i = 0; i < (int)kv.size(); i++) {
            if (kv[i] == n) return true;
        }
        return false;
    }
    for (int i = 0; i < (int)kv.size(); i++) {
        if (kv[i] > n) break;
        if (moze(n - kv[i], k - 1, kv)) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> kv = kvadrati(n);

    for (int k = 1; k <= 4; k++) {
        if (moze(n, k, kv)) {
            cout << k << "\n";
            return 0;
        }
    }

    return 0;
}
