#include <iostream>
#include <set>
#include <queue>

using namespace std;

queue <int> x, y, z;
set <int> square_distances;

int main() {
    int n;
    cin >> n;
    
    x.push(0);
    y.push(0);
    z.push(0);

    while(!x.empty()) {
        int x1 = x.front();
        int y1 = y.front();
        int z1 = z.front();
        x.pop();
        y.pop();
        z.pop();

        x.push(x1 + 1);
        y.push(y1);
        z.push(z1);
        
        x.push(x1);
        y.push(y1 + 1);
        z.push(z1);
        
        x.push(x1);
        y.push(y1);
        z.push(z1 + 1);
        
        x.push(x1 - 1);
        y.push(y1);
        z.push(z1);
        
        x.push(x1);
        y.push(y1 - 1);
        z.push(z1);
        
        x.push(x1);
        y.push(y1);
        z.push(z1 - 1);
    }

    cout << square_distances.size() << endl;

    return 0;
}