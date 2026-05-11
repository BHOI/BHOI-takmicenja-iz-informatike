#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

const int MAXN = 1001;
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

    // 0-1 BFS: stanje = (red, kolona, smjer)
    // Cijena: nastavak istog smjera = 0, promjena smjera = 1
    // Pocinjemo iz S sa cijenom 1 za svaki pocetni smjer
    deque<tuple<int, int, int>> dq;

    for (int d = 0; d < 4; d++) {
        int nr = sr + dr[d];
        int nc = sc + dc[d];
        if (nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] != '#') {
            if (dist[nr][nc][d] > 1) {
                dist[nr][nc][d] = 1;
                dq.push_back({nr, nc, d});
            }
        }
    }

    while (!dq.empty()) {
        auto [r, c, d] = dq.front();
        dq.pop_front();
        int cur_dist = dist[r][c][d];

        // Preskoci ako je ovo stanje vec obradjeno sa boljom udaljenoscu
        if (cur_dist > dist[r][c][d]) continue;

        for (int nd = 0; nd < 4; nd++) {
            int nr = r + dr[nd];
            int nc = c + dc[nd];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w || grid[nr][nc] == '#')
                continue;

            int cost = (nd == d) ? 0 : 1;
            int new_dist = cur_dist + cost;
            if (new_dist < dist[nr][nc][nd]) {
                dist[nr][nc][nd] = new_dist;
                if (cost == 0)
                    dq.push_front({nr, nc, nd});
                else
                    dq.push_back({nr, nc, nd});
            }
        }
    }

    int ans = INF;
    for (int d = 0; d < 4; d++)
        ans = min(ans, dist[cr][cc][d]);
    cout << ans << "\n";

    return 0;
}
