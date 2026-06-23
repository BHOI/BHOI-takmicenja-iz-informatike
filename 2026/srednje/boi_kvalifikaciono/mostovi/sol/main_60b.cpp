#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// Korektno rjesenje ali sa sporim upitima O(M) po upitu
// Radi za M <= 1000, TLE za M = 200000
// Ocekivano: 60 bodova (testovi 0-5)

int n;
set<int> dead;
vector<pii> bridges; // lista mostova {x, y} gdje x < n, y >= n

// Provjeri moze li se ici od x do y na sjevernoj obali (x < y, oba < n)
bool canGoNorth(int x, int y) {
    auto it = dead.lower_bound(x);
    return it == dead.end() || *it >= y;
}

// Provjeri moze li se ici od x do y na juznoj obali (x > y, oba >= n)
bool canGoSouth(int x, int y) {
    auto it = dead.lower_bound(y);
    return it == dead.end() || *it >= x;
}

// Pronadji most koji je najblize desno od pozicije x na sjeveru (ili y na jugu)
// Vraca {north_end, south_end} ili {-1,-1}
pii findBridgeRight(int x, int y) {
    pii best = {-1, -1};
    for (int i = 0; i < (int)bridges.size(); i++) {
        int bn = bridges[i].first;
        int bs = bridges[i].second;
        if (bn >= x && bs >= y) {
            if (best.first == -1 || bn < best.first || (bn == best.first && bs < best.second)) {
                best = {bn, bs};
            }
        }
    }
    return best;
}

// Pronadji most koji je najblize lijevo od pozicije x na sjeveru (ili y na jugu)
pii findBridgeLeft(int x, int y) {
    pii best = {-1, -1};
    for (int i = 0; i < (int)bridges.size(); i++) {
        int bn = bridges[i].first;
        int bs = bridges[i].second;
        if (bn <= x && bs <= y) {
            if (best.first == -1 || bn > best.first || (bn == best.first && bs > best.second)) {
                best = {bn, bs};
            }
        }
    }
    return best;
}

bool check(int x, int y) {
    if (x == -1 || y == -1) return false;
    if (x == y) return true;

    // Oba na sjevernoj strani
    if (x < n && y < n) {
        if (x < y) {
            return canGoNorth(x, y);
        } else {
            // Moramo ici desno do mosta, prijeci na jug, i onda nazad
            pii m = findBridgeRight(x, -1);
            if (m.first == -1) return false;
            return check(x, m.first) && check(m.second, y);
        }
    }

    // Oba na juznoj strani
    if (x >= n && y >= n) {
        if (x > y) {
            return canGoSouth(x, y);
        } else {
            // Moramo ici lijevo do mosta, prijeci na sjever, i onda nazad
            pii m = findBridgeLeft(n, x);
            if (m.first == -1) return false;
            return check(x, m.second) && check(m.first, y);
        }
    }

    // Na suprotnim stranama
    if (x < n) {
        pii m = findBridgeRight(x, y);
        if (m.first == -1) return false;
        return check(x, m.first) && check(m.second, y);
    } else {
        pii m = findBridgeLeft(y, x);
        if (m.first == -1) return false;
        return check(x, m.second) && check(m.first, y);
    }
}

int main(void) {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        char tip[5];
        int x, y;
        scanf("%s %d %d", tip, &x, &y);
        x--; y--;

        if (tip[0] == 'Q') {
            if (check(x, y)) puts("DA");
            else puts("NE");
        }

        if (x > y) swap(x, y);
        if (tip[0] == 'B') dead.insert(x);
        if (tip[0] == 'A') bridges.push_back({x, y});
    }
    return 0;
}
