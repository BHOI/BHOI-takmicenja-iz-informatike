#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(2, vector<int>(2 * n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cin >> g[i][j];
        }
    }

    // BFS na stanju grida
    // stanje = cijeli grid kao vektor
    // radi samo za male N
    int cols = 2 * n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<int> start_state;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < cols; j++) {
            start_state.push_back(g[i][j]);
        }
    }

    set<vector<int>> visited;
    queue<pair<vector<int>, int>> q;
    q.push({start_state, 0});
    visited.insert(start_state);

    int ans = 1<<29;

    while (!q.empty()) {
        vector<int> state = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (dist >= ans) continue;

        // provjeri da li su sve 4 gume Hrvojevog auta jednake
        // pozicije: (0,0), (0,1), (1,0), (1,1) -> indeksi 0, 1, cols, cols+1
        int v0 = state[0];
        int v1 = state[1];
        int v2 = state[cols];
        int v3 = state[cols + 1];
        if (v0 == v1 && v1 == v2 && v2 == v3) {
            ans = min(ans, dist);
            continue;
        }

        if (dist >= 20) continue;

        // probaj sve zamjene susjednih
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < cols; j++) {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    if (ni < 0 || ni >= 2 || nj < 0 || nj >= cols) continue;
                    int idx1 = i * cols + j;
                    int idx2 = ni * cols + nj;
                    if (state[idx1] == state[idx2]) continue;
                    vector<int> nstate = state;
                    int tmp = nstate[idx1];
                    nstate[idx1] = nstate[idx2];
                    nstate[idx2] = tmp;
                    if (!visited.count(nstate)) {
                        visited.insert(nstate);
                        q.push({nstate, dist + 1});
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
