#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int MNOGO = 1<<29;

int main(){
    // Svi pozitivne energetske cijene
    // Dijkstra (podzadatak 1 + podzadatak 4)

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(m), b(m), e(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> e[i];
    }

    vector<int> y(n), z(n);
    for(int i = 0; i < n; i++){
        cin >> y[i] >> z[i];
    }

    vector<int> s(q), t(q);
    for(int i = 0; i < q; i++){
        cin >> s[i] >> t[i];
    }


    vector<vector<pair<int, int>>> adj_list(n);
    for(int i = 0; i < m; i++){
        adj_list[a[i]].emplace_back(b[i], e[i]);
    }

    vector<bool> started_from(n, false);

    for(int i = 0; i < q; i++){
        int start = s[i];
        int end = t[i];

        if(!started_from[start]) {
            adj_list[start].push_back(make_pair(y[start], z[start]));
            started_from[start] = true;
        }

        // Svaki put Dijkstrin algoritam sa najnovijim skupom poteza
        vector<int> dist(n, MNOGO);
        dist[start] = 0;;

        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, start)); // (distance, node)

        vector<bool> visited(n, false);

        while(!pq.empty()) {
            int d = -pq.top().first; // Negiramo da bi koristili min-heap
            int u = pq.top().second;
            pq.pop();

            if(visited[u]) continue;
            visited[u] = true;

            if(d > dist[u]) continue;

            for(int j = 0; j < adj_list[u].size(); j++) {
                int v = adj_list[u][j].first;
                int weight = adj_list[u][j].second;

                if(dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(-dist[v], v)); // Negiramo da bi koristili min-heap
                }
            }
        }

        if(dist[end] == MNOGO) {
            cout << "NEMOGUCE" << endl;
        } else {
            cout << dist[end] << endl;
        }
    }

    return 0;
}