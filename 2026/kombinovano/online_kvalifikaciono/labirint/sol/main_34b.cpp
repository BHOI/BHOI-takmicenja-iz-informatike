#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 11;
const int INF = 1e9;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

char grid[MAXN][MAXN];
int dist[MAXN][MAXN][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    int sr, sc, cr, cc;
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') { sr = i; sc = j; }
            if (grid[i][j] == 'C') { cr = i; cc = j; }
        }
    }

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            for (int d = 0; d < 4; d++)
                dist[i][j][d] = INF;

    // BFS sa queue: stanje = (red, kolona, smjer, broj_skretanja)
    // Radi tacno ali sporo za velike matrice jer koristi MAXN = 11
    queue<tuple<int, int, int, int>> q;

    for (int d = 0; d < 4; d++) {
        int nr = sr + dr[d];
        int nc = sc + dc[d];
        if (nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] != '#') {
            if (dist[nr][nc][d] > 1) {
                dist[nr][nc][d] = 1;
                q.push({nr, nc, d, 1});
            }
        }
    }

    while (!q.empty()) {
        auto [r, c, d, turns] = q.front();
        q.pop();

        if (turns > dist[r][c][d]) continue;

        for (int nd = 0; nd < 4; nd++) {
            int nr = r + dr[nd];
            int nc = c + dc[nd];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w || grid[nr][nc] == '#')
                continue;

            int new_turns = turns + (nd != d ? 1 : 0);
            if (new_turns < dist[nr][nc][nd]) {
                dist[nr][nc][nd] = new_turns;
                q.push({nr, nc, nd, new_turns});
            }
        }
    }

    int ans = INF;
    for (int d = 0; d < 4; d++)
        ans = min(ans, dist[cr][cc][d]);
    cout << ans << "\n";

    return 0;
}
