#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    if((a == c && b == d) || (a == d && b == c)) {
        cout << n - 2 << endl;
        return 0;
    }

    if(a == c || b == d || a == d || b == c) {
        cout << n - 3 << endl;
        return 0;
    }

    cout << n - 4 << endl;

    return 0;
}
