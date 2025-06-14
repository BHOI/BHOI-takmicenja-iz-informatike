#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
const int mxn = 1e5;
const int mxv = 1e5;
vector<int> stl = vector<int>(4 * mxv);
vector<int> str = vector<int>(4 * mxv);


void upd(vector<int>& st, int c, int tl, int tr, int p, int v) {
	if (tl == tr) {
		st[c] += v;
		return;
	}
	int tm = (tl + tr) / 2;
	if (p <= tm)
		upd(st, 2 * c, tl, tm, p, v);
	else
		upd(st, 2 * c + 1, tm + 1, tr, p, v);
	
	st[c] = st[2 * c] + st[2 * c + 1];
}

int qry(vector<int>& st, int c, int tl, int tr, int l, int r) {
	if (tr < l or tl > r)
		return 0;
	if (l <= tl and tr <= r)
		return st[c];

	int tm = (tl + tr) / 2;
	int left = qry(st, 2 * c, tl, tm, l, r);
	int right = qry(st, 2 * c + 1, tm + 1, tr, l, r);

	return left + right;
}

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		upd(str, 1, 1, mxv, h[i], 1);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int smaller_right = qry(str, 1, 1, mxv, 1, h[i] - 1);
		int larger_right = qry(str, 1, 1, mxv, h[i] + 1, mxv);

		int smaller_left = qry(stl, 1, 1, mxv, 1, h[i] - 1);
		int larger_left = qry(stl, 1, 1, mxv, h[i] + 1, mxv);

		ans = ((ans % mod) + (((smaller_left % mod) * (larger_right % mod)) % mod)) % mod;
		ans = ((ans % mod) + (((larger_left % mod) * (smaller_right % mod)) % mod)) % mod;

		upd(stl, 1, 1, mxv, h[i], 1);
		upd(str, 1, 1, mxv, h[i], -1);
	}

	cout << ans << endl;
}