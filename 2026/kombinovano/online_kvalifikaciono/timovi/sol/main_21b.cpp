#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<pair<int,int>> edges;
    vector<pair<int,int>> edge_list;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.insert({a, b});
        edge_list.push_back({a, b});
    }

    // Brute force: probaj sve podskupove cvorova (za M <= 10, bitni su samo cvorovi iz ivica)
    // Sakupi sve cvorove koji se pojavljuju u ivicama
    set<int> nodes_set;
    for (auto [a, b] : edge_list) {
        nodes_set.insert(a);
        nodes_set.insert(b);
    }
    vector<int> nodes(nodes_set.begin(), nodes_set.end());
    int k = nodes.size();

    int best = 1;

    // Probaj sve podskupove
    for (int mask = 1; mask < (1 << k); mask++) {
        vector<int> subset;
        for (int i = 0; i < k; i++)
            if (mask & (1 << i))
                subset.push_back(nodes[i]);

        int sz = subset.size();
        if (sz <= best) continue;

        // Provjeri da li svi parovi mogu doci jedan do drugog usmjerenim putevima unutar podskupa
        set<int> sub_set(subset.begin(), subset.end());
        bool valid = true;

        for (int i = 0; i < sz && valid; i++) {
            // BFS/DFS iz subset[i], provjeri da li su svi ostali dostupni
            set<int> reachable;
            vector<int> stack = {subset[i]};
            reachable.insert(subset[i]);
            while (!stack.empty()) {
                int v = stack.back();
                stack.pop_back();
                for (auto [a, b] : edge_list) {
                    if (a == v && sub_set.count(b) && !reachable.count(b)) {
                        reachable.insert(b);
                        stack.push_back(b);
                    }
                }
            }
            for (int j = 0; j < sz; j++) {
                if (!reachable.count(subset[j])) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) best = sz;
    }

    cout << best << "\n";
    return 0;
}
