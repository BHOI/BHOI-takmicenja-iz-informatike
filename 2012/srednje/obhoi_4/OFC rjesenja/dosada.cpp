#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	freopen("dosada.in", "r", stdin);
	freopen("dosada.out", "w", stdout);
	int n,m,size=1;
	int A[500000];
	scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++)
		scanf("%d", &A[i]);
	sort(A, A+n);
	for (int i=1;i<n;i++)
		if (A[i]!=A[i-1]) A[size++]=A[i];
	while (m-->0){
		scanf("%d", &n);
		if (n>=size) puts("nema");
		else printf("%d\n", A[n]);
	}
	return 0;
}
