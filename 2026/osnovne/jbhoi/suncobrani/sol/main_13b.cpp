#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> A(n), B(n), D(n);
    vector<int> prot(11, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> D[i];
        for(int j = A[i]; j <= B[i]; j++) {
            prot[j] += D[i];
        }
    }

    int best_start = -10;
    int best_sum = -1;
    for (int i = -10; i <= 10; i++) {
        int s = 0;
        for (int j = i; j < i + l; j++) {
            if (j >= 1 && j <= 10) {
                s += prot[j];
            }
        }
        if (s > best_sum) {
            best_sum = s;
            best_start = i;
        }
    }

    cout << best_start << " " << (best_start + l - 1) << endl;

    return 0;
}
