// u proslom rjesenju imamo
// 1*BP(n*(n+1)/2-1)+2*BP(n*(n+1)/2-2)+...+n*BP(n*(n+1)/2-n)
// = BP*(1*(n*(n+1)/2-1) + 2*(n*(n+1)/2-2) + ... + n*(n*(n+1)/2-n))
// izvucemo n*(n+1)/2 i dio koji oduzimamo za svaki clan
// = BP*(1*(n*(n+1))/2 + .. + n*(n*(n+1)/2) - (1*1+...n*n))
// = BP*( (n*(n+1)/2) * (1+..+n) - (1*1+...n*n))
// = BP*( (n*(n+1)/2)^2 - (1*1+...n*n) )
// mozemo prije vremena inicijalizirati sumu kvadrata i sve BP-ove tako da svaki slucaj mozemo rijesiti u O(1) vremenu
#include <bits/stdc++.h>
#define mp make_pair
#define all(a) a.begin(), a.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<ll> facts(maxn, 1);
    vector<ll> sum_kvad(maxn, 0);
    for (ll i = 1; i < maxn; i++) {
        facts[i] = facts[i - 1] * i % mod;
        sum_kvad[i] = sum_kvad[i - 1] + i * i;
        sum_kvad[i] %= mod;
    }

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll sum_all = (n * (n + 1) / 2) % mod;
        ll base = sum_all * sum_all % mod - sum_kvad[n]; base %= mod;
        if (base < 0)
            base += mod;
        base *= facts[n - 2], base %= mod;
        base *= n - 1LL, base %= mod;
        cout << base << "\n";
    }
}