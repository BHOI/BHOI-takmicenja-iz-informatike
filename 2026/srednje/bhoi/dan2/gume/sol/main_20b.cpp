#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<vector<int>> mat(2, vector<int>(2 * n));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cin >> mat[i][j];
        }
    }

    // Naci prvu velicinu gume koja se pojavljuje 4 puta
    map<int, vector<pair<int, int>>> positions;
    int guma = -1;

    for (int i = 0; i < 2 * n; i++) {
        positions[mat[0][i]].push_back({0, i});
        positions[mat[1][i]].push_back({1, i});

        if(positions[mat[0][i]].size() >= 4) {
            guma = mat[0][i];
            break;
        }

        if(positions[mat[1][i]].size() >= 4) {
            guma = mat[1][i];
            break;
        }
    }

    // Znamo da guma nece ostati -1 zato sto je zadano da barem jedne velicine ima 4 puta

    pair<int, int> a = positions[guma][0];
    pair<int, int> b = positions[guma][1];
    pair<int, int> c = positions[guma][2];
    pair<int, int> d = positions[guma][3];

    // Sada imamo 4 pozicije gume, trebamo ih dovesti na (0,0), (0,1), (1,0), (1,1)

    // Pretpostavimo da a ide na (0,0), b na (0,1), c na (1,0), d na (1,1)

    int ans = 0;

    // Za svaki od 4 para racunamo koliko je potrebno pomjeranja
    ans += abs(a.first - 0) + abs(a.second - 0);
    ans += abs(b.first - 0) + abs(b.second - 1);
    ans += abs(c.first - 1) + abs(c.second - 0);
    ans += abs(d.first - 1) + abs(d.second - 1);

    cout << ans << endl;

    return 0;
}
