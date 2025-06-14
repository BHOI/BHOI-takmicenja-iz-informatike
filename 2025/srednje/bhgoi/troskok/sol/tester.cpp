#include <iostream>
#include <vector>

#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
using namespace std;

// RECURSIVE
struct Seg {
    vector<int> seggy;
    Seg(int n) {
        seggy = vector<int>(4 * n);
    }
    int update(int i, int l, int r, int qi, int qv) {
        if(qi < l || r < qi) return seggy[i];
        if(l == r) {
            return seggy[i] = qv;
        }
        return seggy[i] = update(2 * i, l, (l + r) / 2, qi, qv) + update(2 * i + 1, (l + r) / 2 + 1, r, qi, qv);
    }
    int query(int i, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return seggy[i];
        return query(2 * i, l, (l + r) / 2, ql, qr) + query(2 * i + 1, (l + r) / 2 + 1, r, ql, qr);
    }
};

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    Seg segh(1e4+2), segl(1e4+2), segc(1e4+2);
    int res = 0;
    for(int i = n - 1; i > -1; i--) {
        res += segh.query(1, 0, 1e4+1, a[i] + 1, 1e4+1);
        segh.update(1, 0, 1e4+1, a[i], segc.query(1, 0, 1e4+1, a[i] + 1, 1e4+1));
        res += segl.query(1, 0, 1e4+1, 0, a[i] - 1);
        segl.update(1, 0, 1e4+1, a[i], segc.query(1, 0, 1e4+1, 0, a[i] - 1));
        segc.update(1, 0, 1e4+1, a[i], 1);
    }
    cout << res%1000000007 << "\n";
}