#include <cstdio>
#include <iostream>
using namespace std;

int main (void) {
	freopen ("jedinice.in", "r", stdin);
	freopen ("jedinice.out", "w", stdout);

	int n;
	scanf ("%d", &n);
	int res = 1, temp = 1;
	while (true) {
		temp = 10 * temp + 1; res++;
		if ((temp = temp % n) == 0) break;
	}
	printf ("%d\n", res);

	return 0;
}

