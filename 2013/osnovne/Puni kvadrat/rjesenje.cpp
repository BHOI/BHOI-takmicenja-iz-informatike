#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef long long ll;

ll sqr (ll x) {
	return x * x;
}

ll f (ll x) {
	if (x < 1) return 0;
	
	ll r = sqrt (x);	
	if (sqr (r) > x) return r - 1;
	if (sqr (r + 1) == x) return r + 1;
	return r;
}

int main () {
	ll a, b;
	
	scanf ("%lld %lld", &a, &b);
	
	if (b < a) swap (a, b);
	
	printf ("%lld\n", f(b) - f(a - 1));
	
	return 0;
}
