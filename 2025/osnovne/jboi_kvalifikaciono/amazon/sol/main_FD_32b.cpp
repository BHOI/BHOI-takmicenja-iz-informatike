#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
  
const int MOD = 998244353;
const int INF = 1e9; 
 
int gcd(int a, int b, int& x, int& y) { // x*a + y*b = a1 
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
 
int inv_ecd(int a, int m) {
    int x, y;
    int g = gcd(a, m, x, y);
    if(g != 1) return -1;
    x = (x + m) % m;
    return x;
}
 
int thrw(int x) { 
    int ans;
    cout << "throw " << x << endl; 
    cin >> ans;
    return ans;
}
 
void swp(int x) { cout << "swap " << x << endl; }  
 
void solve() {
    int a,b;
    string s;
    cin >> a >> b >> s;
    --a, --b;
    int n = (int)s.length();
    vi dep(n, 0);
    for(int i=0; i<n; ++i) {
        dep[i] = (s[i] == 'U' ? 1: -1);
        if(i) dep[i] += dep[i-1];
    }
    int mi = dep[a];
    for(int i=a+1; i<=b; ++i) mi = min(mi, dep[i]);
    cout << (abs(dep[a] - mi) + abs(dep[b] - mi)) << endl;
}
  
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
     
    int tc = 1;
    while (tc--) solve();   
}