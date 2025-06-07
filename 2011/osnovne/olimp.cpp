#include <cstdio>
using namespace std;

int main()
{
	freopen("olimp.in", "r", stdin);
	freopen("olimp.out", "w", stdout);
	int A[200001] = {}, n, q, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &A[i]);
		A[i] += A[i-1];
	}
	scanf("%d", &q);
	while (q > 0){
		scanf("%d%d", &a, &b);
		printf("%d\n", A[b] - A[a-1]);
		q--;
	}
	return 0;
}
