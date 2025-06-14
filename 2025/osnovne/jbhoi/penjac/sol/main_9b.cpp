#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    // Svi E i Z su jednaki 1
    // BFS, koristimo matricu susjedstva

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

    vector<vector<bool>> adj_matrix(n, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        adj_matrix[a[i]][b[i]] = true;
    }

    for(int i = 0; i < q; i++){
        int start = s[i];
        int top = t[i];

        // Otkljucavanje poteza
        adj_matrix[start][y[start]] = true;

        vector<int> dist(n, -1);
        queue<int> bfs_queue;
        bfs_queue.push(start);
        dist[start] = 0;
        while(!bfs_queue.empty()){
            int current = bfs_queue.front();
            bfs_queue.pop();

            for(int j = 0; j < n; j++){
                if(adj_matrix[current][j] && dist[j] == -1){
                    dist[j] = dist[current] + 1;
                    bfs_queue.push(j);
                }
            }
        }

        if(dist[top] != -1){
            cout << dist[top] << endl;
        } else {
            cout << "NEMOGUCE" << endl;
        }
    }


    return 0;
}