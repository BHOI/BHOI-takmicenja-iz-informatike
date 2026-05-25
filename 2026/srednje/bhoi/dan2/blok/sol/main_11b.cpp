#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// Rjesenje samo za podzadatak 1: H = 1
// U jednom redu blok moze biti uspravno (0) ili lezati u redu (1)
// Nema orijentacije kolone jer H=1

const int MAXW = 501;
char grid[MAXW];
bool visited[MAXW][2]; // [kolona][orijentacija: 0=uspravan, 1=lezi u redu]
int w;

bool ok(int c) {
    return c >= 0 && c < w && grid[c] != '#';
}

int main() {
    int h;
    cin >> h >> w;
    cin >> grid;

    int sc = -1, cc = -1;
    for (int j = 0; j < w; j++) {
        if (grid[j] == 'S') { sc = j; grid[j] = '.'; }
        if (grid[j] == 'C') { cc = j; grid[j] = '.'; }
    }

    memset(visited, false, sizeof(visited));

    // BFS: stanje (kolona, orijentacija)
    queue<pair<int, int>> q;
    q.push({sc, 0});
    visited[sc][0] = true;

    while (!q.empty()) {
        auto [c, o] = q.front();
        q.pop();

        if (c == cc && o == 0) {
            cout << "DA" << endl;
            return 0;
        }

        int nc, no;

        if (o == 0) {
            // Uspravan na c
            // Lijevo: lezi na (c-2, c-1)
            nc = c - 2; no = 1;
            if (ok(nc) && ok(nc + 1) && !visited[nc][no]) {
                visited[nc][no] = true;
                q.push({nc, no});
            }
            // Desno: lezi na (c+1, c+2)
            nc = c + 1; no = 1;
            if (ok(nc) && ok(nc + 1) && !visited[nc][no]) {
                visited[nc][no] = true;
                q.push({nc, no});
            }
        } else {
            // Lezi u redu na (c, c+1)
            // Lijevo: ustaje na c-1
            nc = c - 1; no = 0;
            if (ok(nc) && !visited[nc][no]) {
                visited[nc][no] = true;
                q.push({nc, no});
            }
            // Desno: ustaje na c+2
            nc = c + 2; no = 0;
            if (ok(nc) && !visited[nc][no]) {
                visited[nc][no] = true;
                q.push({nc, no});
            }
        }
    }

    cout << "NE" << endl;
    return 0;
}
