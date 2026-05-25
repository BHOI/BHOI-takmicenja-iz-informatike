#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// Orijentacije:
// 0 = uspravno (zauzima 1 polje: (r,c))
// 1 = lezi u smjeru reda (zauzima (r,c) i (r,c+1))
// 2 = lezi u smjeru kolone (zauzima (r,c) i (r+1,c))

int h, w;
vector<string> grid;

bool ok(int r, int c) {
    return r >= 0 && r < h && c >= 0 && c < w && grid[r][c] != '#';
}

int main() {
    cin >> h >> w;
    grid.resize(h);
    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(3, false)));

    int sr, sc, cr, cc;
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') { sr = i; sc = j; grid[i][j] = '.'; }
            if (grid[i][j] == 'C') { cr = i; cc = j; grid[i][j] = '.'; }
        }
    }

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

        // Generisanje svih mogucih poteza
        // nr, nc = novi red/kolona, no = nova orijentacija
        int nr, nc, no;

        if (o == 0) {
            // Uspravno na (r,c)
            // Gore: prevrne se na kolonu, zauzima (r-2,c) i (r-1,c)
            nr = r - 2; nc = c; no = 2;
            if (ok(nr, nc) && ok(nr + 1, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            // Dolje: prevrne se na kolonu, zauzima (r+1,c) i (r+2,c)
            nr = r + 1; nc = c; no = 2;
            if (ok(nr, nc) && ok(nr + 1, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            // Lijevo: prevrne se na red, zauzima (r,c-2) i (r,c-1)
            nr = r; nc = c - 2; no = 1;
            if (ok(nr, nc) && ok(nr, nc + 1) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            // Desno: prevrne se na red, zauzima (r,c+1) i (r,c+2)
            nr = r; nc = c + 1; no = 1;
            if (ok(nr, nc) && ok(nr, nc + 1) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
        } else if (o == 1) {
            // Lezi u smjeru reda: (r,c) i (r,c+1)
            // Gore: pomak za 1 gore, i dalje lezi u redu: (r-1,c) i (r-1,c+1)
            nr = r - 1; nc = c; no = 1;
            if (ok(nr, nc) && ok(nr, nc + 1) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            // Dolje: pomak za 1 dolje: (r+1,c) i (r+1,c+1)
            nr = r + 1; nc = c; no = 1;
            if (ok(nr, nc) && ok(nr, nc + 1) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            // Lijevo: ustaje na (r,c-1)
            nr = r; nc = c - 1; no = 0;
            if (ok(nr, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            // Desno: ustaje na (r,c+2)
            nr = r; nc = c + 2; no = 0;
            if (ok(nr, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
        } else {
            // Lezi u smjeru kolone: (r,c) i (r+1,c)
            // Gore: ustaje na (r-1,c)
            nr = r - 1; nc = c; no = 0;
            if (ok(nr, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            // Dolje: ustaje na (r+2,c)
            nr = r + 2; nc = c; no = 0;
            if (ok(nr, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            // Lijevo: pomak za 1 lijevo: (r,c-1) i (r+1,c-1)
            nr = r; nc = c - 1; no = 2;
            if (ok(nr, nc) && ok(nr + 1, nc) && !visited[nr][nc][no]) {
                visited[nr][nc][no] = true;
                q.push({nr, nc, no});
            }
            // Desno: pomak za 1 desno: (r,c+1) i (r+1,c+1)
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
