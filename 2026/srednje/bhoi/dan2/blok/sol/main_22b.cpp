#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// Rjesenje za podzadatke 1 i 2: H <= 2
// Puni BFS ali sa ogranicenjem da radi samo za H <= 2

const int MAXN = 501;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN][3];
int h, w;

bool ok(int r, int c) {
    return r >= 0 && r < h && c >= 0 && c < w && grid[r][c] != '#';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;

    if (h > 2) {
        // Ne zna rijesiti
        // Procitaj matricu i ispisi NE
        for (int i = 0; i < h; i++) cin >> grid[i];
        cout << "NE" << endl;
        return 0;
    }

    int sr, sc, cr, cc;
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') { sr = i; sc = j; grid[i][j] = '.'; }
            if (grid[i][j] == 'C') { cr = i; cc = j; grid[i][j] = '.'; }
        }
    }

    memset(visited, false, sizeof(visited));

    queue<tuple<int, int, int>> q;
    q.push({sr, sc, 0});
    visited[sr][sc][0] = true;

    while (!q.empty()) {
        auto [r, c, o] = q.front();
        q.pop();

        if (r == cr && c == cc && o == 0) {
            cout << "DA" << endl;
            return 0;
        }

        int nr, nc, no;

        if (o == 0) {
            nr = r - 2; nc = c; no = 2;
            if (ok(nr, nc) && ok(nr + 1, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            nr = r + 1; nc = c; no = 2;
            if (ok(nr, nc) && ok(nr + 1, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            nr = r; nc = c - 2; no = 1;
            if (ok(nr, nc) && ok(nr, nc + 1) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            nr = r; nc = c + 1; no = 1;
            if (ok(nr, nc) && ok(nr, nc + 1) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
        } else if (o == 1) {
            nr = r - 1; nc = c; no = 1;
            if (ok(nr, nc) && ok(nr, nc + 1) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            nr = r + 1; nc = c; no = 1;
            if (ok(nr, nc) && ok(nr, nc + 1) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            nr = r; nc = c - 1; no = 0;
            if (ok(nr, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            nr = r; nc = c + 2; no = 0;
            if (ok(nr, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
        } else {
            nr = r - 1; nc = c; no = 0;
            if (ok(nr, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            nr = r + 2; nc = c; no = 0;
            if (ok(nr, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            nr = r; nc = c - 1; no = 2;
            if (ok(nr, nc) && ok(nr + 1, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            nr = r; nc = c + 1; no = 2;
            if (ok(nr, nc) && ok(nr + 1, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
        }
    }

    cout << "NE" << endl;
    return 0;
}
