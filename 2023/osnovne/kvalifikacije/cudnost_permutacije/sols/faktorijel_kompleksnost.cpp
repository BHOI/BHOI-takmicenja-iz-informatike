// ovo rješenje proba svaku permutaciju i izračuna pojedinačno vrijednost
#include <bits/stdc++.h>
#define mp make_pair
#define all(a) a.begin(), a.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            perm[i] = i + 1;
        ll sum = 0;
        do {
            for (int i = 0; i < n - 1; i++)
                sum += perm[i] * perm[i + 1], sum %= mod;
        } while (next_permutation(all(perm)));

        cout << sum << "\n";
    }
}