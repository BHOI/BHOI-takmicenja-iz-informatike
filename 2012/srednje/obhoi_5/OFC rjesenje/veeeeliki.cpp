#include <cstdio>
#include <cstring>
using namespace std;

#define LL long long

LL modular_exponentation(LL base, LL exponent, LL mod)
{
	LL res = (exponent%2) ? base%mod:1;
	while (exponent >>= 1){
		base = (base*base)%mod;
		if (exponent%2) res = (res*base)%mod;
	}
	return res;
}

LL big_base_mod(char A[], int n, LL mod)
{
	LL res = 0, y = 1;
	for (int i = n-1; i>=0; i--){
		res += ( ( (A[i]-'0')%mod ) * y )%mod;
		res %= mod;
		y = (y * (10%mod))%mod;
	}
	return res;
}

LL big_exponent_mod(char K[], int n, LL base, LL mod)
{
	LL y = base;
	LL res = modular_exponentation(y, K[ strlen(K)-1 ] - '0', mod);
	for (int i = n-2; i>=0; i--){
		y = modular_exponentation(y, 10, mod);
		res = ( res * modular_exponentation(y, K[i] - '0', mod) )%mod;
	}
	return res;
}

char N[1000005], K[1000005];

int main()
{
	//freopen("veeeeliki.in", "r", stdin);
	//freopen("veeeeliki.out", "w", stdout);
	long long M, x, res, y;
	scanf("%s %s %lld", N, K, &M);
	x = big_base_mod(N, strlen(N), M);
	res = big_exponent_mod(K, strlen(K), x, M);
	printf("%lld\n", res);
	return 0;
}

