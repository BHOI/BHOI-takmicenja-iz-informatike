#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1001;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int h, w, cr, cc;
int ans;

// DFS za pronalazenje jedinstvenog puta i brojanje promjena smjera
void dfs(int r, int c, int prev_dir, int turns) {
    if (r == cr && c == cc) {
        ans = turns;
        return;
    }

    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
        if (grid[nr][nc] == '#' || visited[nr][nc]) continue;

        int new_turns = turns + (d != prev_dir ? 1 : 0);
        visited[nr][nc] = true;
        dfs(nr, nc, d, new_turns);
        visited[nr][nc] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;

    int sr, sc;
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') { sr = i; sc = j; }
            if (grid[i][j] == 'C') { cr = i; cc = j; }
        }
    }

    // Podzadatak 1 (nema zidova): isti red/kolona -> 1, inace 2
    bool has_walls = false;
    for (int i = 0; i < h && !has_walls; i++)
        for (int j = 0; j < w && !has_walls; j++)
            if (grid[i][j] == '#') has_walls = true;

    if (!has_walls) {
        if (sr == cr || sc == cc)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
        return 0;
    }

    // Podzadatak 2 (jedinstven put): DFS za pracenje puta
    ans = -1;
    memset(visited, false, sizeof(visited));
    visited[sr][sc] = true;

    for (int d = 0; d < 4; d++) {
        int nr = sr + dr[d];
        int nc = sc + dc[d];
        if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
        if (grid[nr][nc] == '#' || visited[nr][nc]) continue;
        visited[nr][nc] = true;
        dfs(nr, nc, d, 1);
        visited[nr][nc] = false;
        if (ans != -1) break;
    }

    cout << ans << "\n";
    return 0;
}
