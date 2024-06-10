// za svaki par brojeva, prebrojimo u koliko permutacija se pojavi
// dobijemo da par brojeva može biti na (n - 1) mjesta
// broj načina da popunimo ostalih (n-2) mjesta je (n-2)!
// dobijemo za neka dva brojea a, b, ukupno se pojavi (n-1)*(n-2)! puta u sumi i doprinijece a*b*(n-1)*(n-2)!
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
        ll fakt = 1;
        for (int i = 1; i <= n - 2; i++)
            fakt *= i, fakt %= mod;

        ll sum = 0;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (i == j)
                    continue;
                sum += i * j % mod * fakt % mod * (ll)(n - 1) % mod;
                sum %= mod;
            }
        }

        cout << sum << "\n";
    }
}