// primjetimo linearnost proslog rjesenja
// recimo da je BP = (n-1)*(n-2)!
// za neki broj a mi cemo dodati na sumu a*BP*1 + a*BP*2 + ... a*BP*n - a*a*BP
// tj. a*BP*(1+2+..+n-a) = a*BP*(n*(n+1)/2-a)
// ovo znaci mozemo izracunati ovo za svaki broj i sabrati
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
        ll n;
        cin >> n;
        ll fakt = 1;
        for (int i = 1; i <= n - 2; i++)
            fakt *= i, fakt %= mod;

        ll sum = 0; ll sum_all = n * (n + 1LL) / 2LL; sum_all %= mod;
        for (ll i = 1; i <= n; i++) {
            sum += i * (sum_all - i) % mod * fakt % mod * (n - 1LL) % mod;
            sum %= mod;
            if (sum < 0)
                sum += mod;
        }

        cout << sum << "\n";
    }
}