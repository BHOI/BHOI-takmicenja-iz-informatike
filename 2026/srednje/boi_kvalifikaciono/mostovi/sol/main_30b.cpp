#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Brute-force BFS rjesenje za male N
// Radi samo kad N stane u memoriju (N <= ~10^5)
// Ocekivano: 30 bodova (testovi 0-2, N,M <= 1000)

int n;
vector<bool> road_blocked; // road_blocked[i] = cesta od i do i+1 blokirana (sjever), ili od i+1 do i (jug)
vector<pair<int,int>> bridges; // lista mostova

bool bfs(int start, int end_node) {
    if (start == end_node) return true;
    if (n > 200000) return false; // ne moze stati u memoriju

    int total = 2 * n;
    vector<bool> visited(total, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end_node) return true;

        // Sjever: jednosmjerna cesta od cur do cur+1 (ako cur < n-1 i nije blokirana)
        if (cur < n - 1 && !road_blocked[cur]) {
            if (!visited[cur + 1]) {
                visited[cur + 1] = true;
                q.push(cur + 1);
            }
        }

        // Jug: jednosmjerna cesta od cur do cur-1 (ako cur >= n+1 i nije blokirana)
        // Juzna obala: gradovi n..2n-1, cesta ide od veceg prema manjem
        if (cur >= n && cur > n && !road_blocked[cur]) {
            if (!visited[cur - 1]) {
                visited[cur - 1] = true;
                q.push(cur - 1);
            }
        }

        // Mostovi (dvosmjerni)
        for (int i = 0; i < (int)bridges.size(); i++) {
            int u = bridges[i].first;
            int v = bridges[i].second;
            if (cur == u && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
            if (cur == v && !visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    return false;
}

int main(void) {
    int m;
    scanf("%d %d", &n, &m);

    if (n > 200000) {
        // Ne mozemo alocirati nizove, samo ispisujemo NE
        for (int i = 0; i < m; i++) {
            char tip[5];
            int x, y;
            scanf("%s %d %d", tip, &x, &y);
            if (tip[0] == 'Q') puts("NE");
        }
        return 0;
    }

    road_blocked.assign(2 * n, false);

    for (int i = 0; i < m; i++) {
        char tip[5];
        int x, y;
        scanf("%s %d %d", tip, &x, &y);
        x--; y--;

        if (tip[0] == 'A') {
            bridges.push_back({x, y});
        } else if (tip[0] == 'B') {
            // Blokira cestu izmedju x i y (susjedni gradovi)
            if (x > y) swap(x, y);
            // Na sjeveru: cesta od x do x+1 (x < n)
            // Na jugu: cesta od y do y-1 (y >= n), ali oznacavamo sa y
            if (x < n) {
                road_blocked[x] = true;
            } else {
                road_blocked[y] = true;
            }
        } else {
            if (bfs(x, y)) puts("DA");
            else puts("NE");
        }
    }

    return 0;
}
