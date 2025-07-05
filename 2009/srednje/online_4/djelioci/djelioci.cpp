/// 786
// TopCoder SRM 370 Div 1 Hard

#include <iostream>
using namespace std;

bool prime[1005];
long long A[101][50001];
int P[100];
long long lim = 1000000000000000000LL;

long long pow (long long a, int b)
{
	long long res = 1;
	while (b-- > 0) {
		if (res > lim / a) return lim + 1;
		res *= a;
	}
	return res;
}

long long recur (int id, int div)
{
	if (div == 1) return 1;
	if (A[id][div] == -1) {
		A[id][div] = pow(P[id], div - 1);
		for (int i = 2; i * i <= div; i++) if ((div%i) == 0) {
			long long tmp = pow(P[id], i - 1);
			if (tmp > lim / recur(id + 1, div / i))
				tmp = lim + 1;
			else
				tmp *= recur(id + 1, div / i);
			A[id][div] = min(A[id][div], tmp);

			tmp = pow(P[id], (div / i) - 1);
			if (tmp > lim / recur(id + 1, i))
				tmp = lim + 1;
			else
				tmp *= recur(id + 1, i);
			A[id][div] = min(A[id][div], tmp);
		}
	}
	return A[id][div];
}

long long smallestNumber (int k)
{
	int upper = 1000;
	for (int i = 2; i <= upper; i++) prime[i] = true;
	for (int i = 2; i * i <= upper; i++) if (prime[i])
		for (int j = 2*i; j <= upper; j += i) prime[j] = false;

	int tmp = 0;
	for (int i = 2; tmp < 100; i++) if (prime[i]) P[tmp++] = i;

	for (int i = 0; i < 100; i++)
		for (int j = 0; j <= 50000; j++)
			A[i][j] = -1;

	return recur(0,k) <= lim ? recur(0,k) : -1;
}

int main (void)
{
	int k;
	cin >> k;
	long long res = smallestNumber(k);

	cout<<res<<endl;

	return 0;
}
