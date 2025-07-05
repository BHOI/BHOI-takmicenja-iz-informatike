#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXNUM 10001

int main()
{
	freopen("takmicenje.in", "r", stdin);
	freopen("takmicenje.out", "w", stdout);
	int n,k,a;
	int bodovi[MAXNUM]={0};
	int pobjede[MAXNUM]={0};
	scanf("%d %d", &n, &k);
	while (k-->0){
		for (int i=1;i<=n;i++){
			scanf("%d", &a);
			bodovi[i]+=a;
		}
		pobjede[(max_element(bodovi+1, bodovi+n+1)-bodovi)]++;
	}
	printf("%d\n", (max_element(pobjede+1, pobjede+n+1)-pobjede));
	return 0;
}
