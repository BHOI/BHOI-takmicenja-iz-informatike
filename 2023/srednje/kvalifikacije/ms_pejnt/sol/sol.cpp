#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> graph;
vector<bool> visited;

int n;
vector<int> xmin,ymin,xmax,ymax;

// Check if two rectangles overlap
bool overlap(int i, int j) {
    if (xmin[i] >= xmax[j] || xmax[i] <= xmin[j]) return false;
    if (ymin[i] >= ymax[j] || ymax[i] <= ymin[j]) return false;
    return true;
}

// DFS function to count nodes in connected component
int dfs(int node) {
    visited[node] = true;
    int count = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            count += dfs(neighbor);
        }
    }
    return count;
}

// Build graph where nodes are rectangles and two nodes are connected if corresponding rectangles overlap
void buildGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (overlap(i, j)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}


int main() {

    cin >> n;
    visited.resize(n);
    graph.resize(n);
    xmax.resize(n);
    xmin.resize(n);
    ymax.resize(n);
    ymin.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> xmin[i] >> ymin[i] >> xmax[i] >> ymax[i];
        visited[i] = false;
    }

    buildGraph();
    int min_component = n+1, max_component = 0;

    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            auto curr_component = dfs(i);
            min_component = min(min_component, curr_component);
            max_component = max(max_component, curr_component);
        }
    }

    cout << min_component << " " << max_component << endl;

    return 0;
}