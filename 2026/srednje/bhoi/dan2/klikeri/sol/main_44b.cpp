#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;

bool razdvojen(const vector<int>& v, int tip) {
    int n = v.size();
    bool nasao_drugi = false;
    for (int i = 0; i < n; i++) {
        if (v[i] != tip) nasao_drugi = true;
        else if (nasao_drugi) return false;
    }
    return true;
}

int best;
int n;

void backtrack(vector<int>& v, int zamjene) {
    if (zamjene >= best) return;
    if (razdvojen(v, 1) || razdvojen(v, 2)) {
        best = zamjene;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] != v[j]) {
                swap(v[i], v[j]);
                backtrack(v, zamjene + 1);
                swap(v[i], v[j]);
            }
        }
    }
}

int main() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    best = n;
    backtrack(v, 0);

    cout << best << endl;

    return 0;
}
