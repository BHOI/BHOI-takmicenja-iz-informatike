#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Odgovori za N = 1..9: 1,2,3,1,2,3,4,2,1
    int odg[10] = {0, 1, 2, 3, 1, 2, 3, 4, 2, 1};

    if (n >= 1 && n <= 9) {
        cout << odg[n] << "\n";
    }

    return 0;
}
