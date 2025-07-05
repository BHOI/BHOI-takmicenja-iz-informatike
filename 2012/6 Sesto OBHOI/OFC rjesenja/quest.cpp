#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100001
#define MAXLOG 17
#define INF 2147483647

int n, m;
int A[MAXN];
int RMQ[MAXLOG][MAXN];

int minIdx(int a, int b)
{
	if (a>b) return n;
	int row = __lg(b-a+1);
	return (A[ RMQ[row][a] ] < A[ RMQ[row][b - (1<<row) + 1] ]) ? ( RMQ[row][a] ) : ( RMQ[row][b - (1<<row) + 1] );
}

int main()
{
	freopen("quest.in", "r", stdin);
	freopen("quest.out", "w", stdout);
	int q, a, b;
	scanf("%d", &n);
	m = __lg(n);
	for (int i=0; i<n; i++){
		scanf("%d", &A[i]);
		RMQ[0][i] = i;
	}
	A[n] = INF;
	for (int i=1, next = 1; i<=m; i++, next<<=1){
		for (int j=0; j<n; j++){
			RMQ[i][j] = RMQ[i-1][j];
			if (j+next < n && A[ RMQ[i-1][j+next] ] < A[ RMQ[i][j] ])
				RMQ[i][j] = RMQ[i-1][j+next];
		}
	}
	scanf("%d", &q);
	while (q--){
		scanf("%d%d", &a, &b);
		int idx1 = minIdx(a-1, b-1);
		int idx2 = minIdx(a-1, idx1-1);
		int idx3 = minIdx(idx1+1, b-1);
		if (min(idx2, idx3) == n) printf("%lld\n", (long long)A[idx1]*2);
		else printf("%lld\n", (long long)A[idx1] + min(A[idx2], A[idx3]));
	}
	return 0;
}
