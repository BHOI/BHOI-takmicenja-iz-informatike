#include <iostream>
#include <set>

using namespace std;

set <int> square_distances;

void dfs(int x, int y, int z, int n) {
    if(n == 0) {
        square_distances.insert(x * x + y * y + z * z);
        return;
    }
    
    dfs(x + 1, y, z, n - 1);
    dfs(x, y + 1, z, n - 1);
    dfs(x, y, z + 1, n - 1);
    dfs(x - 1, y, z, n - 1);
    dfs(x, y - 1, z, n - 1);
    dfs(x, y, z - 1, n - 1);
}

int main() {
    int n;
    cin >> n;

    dfs(0, 0, 0, n);

    cout << square_distances.size() << endl;

    return 0;
}