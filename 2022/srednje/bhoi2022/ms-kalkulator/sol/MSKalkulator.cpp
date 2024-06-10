#include <iostream>

using namespace std;

long long mod = 1000000007, n, k;
long long arr[100100], pref_right[100100], pref_left[100100];

long long powmod(long long a, long long b, long long _mod) {
    if (b==0) return 1;
    else if (b==1) return a%_mod;
    long long mid = powmod(a,b/2, _mod);
    return ( (b%2==0) ? (mid*mid)%_mod : (a*((mid*mid)%_mod))%_mod );
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    long long step = 1;

    for (int i = n-1; i >= 0; i--) {
        pref_right[i] = step;
        step = (step*arr[i])%(mod-1);
    }
    step = 1;
    for (int i = 0; i < n; ++i) {
        pref_left[i] = step;
        step = (step*arr[i])%(mod-1);
    }

    long long res = powmod(k,(arr[0]*pref_right[0])%(mod-1), mod );
    for (int i = 0; i < n; ++i) {
        long long tmp = powmod( k, (pref_left[i]*pref_right[i])%(mod-1), mod );
        tmp = (tmp * powmod(arr[i], pref_right[i], mod) )%mod;
        res = max(res, tmp);
    }
    cout << res  << endl;

    return 0;
}
