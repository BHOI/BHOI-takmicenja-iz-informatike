#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int mxn = 1e4 + 5;

int N, E;
vector<vector<pair<int, double>>> gr(mxn, vector<pair<int, double>>());
int K, R;

vector<bool> vis(mxn);
vector<double> mx_ties(mxn, 0);

void dfs(int curr, double path_ties) {
    if (curr == R) {
        mx_ties[R] = max(mx_ties[R], path_ties);        
        return;
    }

    vis[curr] = true;
    for (pair<int, double>& edge : gr[curr]) {
        int to = edge.first;
        double edge_ties = edge.second;
        
        if (!vis[to]) {
            dfs(to, path_ties * edge_ties);
        }
    }
    vis[curr] = false;
}

int main() {
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        double g;
        cin >> u >> v >> g;
        gr[u].push_back({v, g});
        gr[v].push_back({u, g});
    }
    cin >> K >> R;
    
    dfs(K, 1);
    cout << mx_ties[R] << endl;
    return 0;
}