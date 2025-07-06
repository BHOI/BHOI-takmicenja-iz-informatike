#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int mxn = 1e4 + 5;

int N, E;
vector<vector<pair<int, double>>> gr(mxn, vector<pair<int, double>>());
int K, R;

vector<double> mn_ties(mxn, 1e9);

void djk() {
    priority_queue<pair<double, int>> pq;
    mn_ties[K] = 1;
    pq.push({1, K});
    
    while (!pq.empty()) {
        int curr = pq.top().second;
        double curr_ties = pq.top().first;
        pq.pop();

        if (curr_ties > mn_ties[curr])
            continue;

        for (pair<int, double> edge : gr[curr]) {
            int to = edge.first;
            double edge_ties = edge.second;
            
            if (curr_ties * edge_ties < mn_ties[to]) {
                mn_ties[to] = curr_ties * edge_ties;
                pq.push({mn_ties[to], to});
            }
        }
    }
}

int main() {
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        double g;
        cin >> u >> v >> g;
        gr[u].push_back({v, 1.0 / g});
        gr[v].push_back({u, 1.0 / g});
    }
    cin >> K >> R;
    
    djk();

    cout << 1 / mn_ties[R] << endl; 
    return 0;
}