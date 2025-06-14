#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 1 upit, mala ogranicenja
    // Floyd-Warshall

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

    int start, top;
    cin >> start >> top;

    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for(int i = 0; i < n; i++){
        dist[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        dist[a[i]][b[i]] = e[i];
    }
    dist[start][y[start]] = z[start];

    // Floyd-Warshall algorithm
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    if(dist[start][top] != 1e9){
        cout << dist[start][top] << endl;
    } else {
        cout << "NEMOGUCE" << endl;
    }

    return 0;
}