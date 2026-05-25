// Kompaktna verzija main.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v1(2 * n), v2(2 * n);
    map<int, vector<int>> m1, m2;
    set<int> unique_vals;

    for (int j = 0; j < 2 * n; j++) {
        cin >> v1[j];
        m1[v1[j]].push_back(j);
        unique_vals.insert(v1[j]);
    }
    for (int j = 0; j < 2 * n; j++) {
        cin >> v2[j];
        m2[v2[j]].push_back(j);
        unique_vals.insert(v2[j]);
    }

    int ans = 1<<28, cost; // 1<<28 je dovoljno veliko da predstavlja "beskonacno" u ovom problemu, a dovoljno malo da ako saberemo 4 takva ne dodje do overflowa

    for (int val : unique_vals) {
        // Uzmi pozicije val u oba reda (vec sortirane po koloni)
        vector<vector<int>> poz;
        poz.push_back(m1[val]);
        poz.push_back(m2[val]);

        // Dodaj "beskonacno" na kraj da izbjegnemo out of range ako je manje od 4 gume ove velicine
        poz[0].resize(4, 1<<28);
        poz[1].resize(4, 1<<28);

        ans = min(ans, poz[0][0] + poz[0][1] + poz[0][2] + poz[0][3]);
        ans = min(ans, poz[0][0] + poz[0][1] + poz[0][2] + poz[1][0] - 1);
        ans = min(ans, poz[0][0] + poz[0][1] + poz[1][0] + poz[1][1] - 2);
        ans = min(ans, poz[0][0] + poz[1][0] + poz[1][1] + poz[1][2] - 1);
        ans = min(ans, poz[1][0] + poz[1][1] + poz[1][2] + poz[1][3]);
    }

    cout << ans << "\n";

    return 0;
}
