#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int sum = 0, a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
    }

    if(sum >= x) {
        cout << "DA\n";
    }
    else {
        cout << "NE\n";
    }

    return 0;
}
