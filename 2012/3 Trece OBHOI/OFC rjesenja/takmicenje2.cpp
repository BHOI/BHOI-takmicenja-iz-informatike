#include <cstdio>
#include <iostream>
using namespace std;

int Tree[65536], LastLevel=1;
int niz[30010];
int entryTime[30010];

inline void ShuffleUp(int i)
{
	int maxi;
	while (i>1){
		int maxi=(i/2)*2;
		if (niz[Tree[maxi+1]]>niz[Tree[maxi]])maxi++;
		else if (niz[Tree[maxi+1]]==niz[Tree[maxi]] && entryTime[Tree[maxi+1]]<entryTime[Tree[maxi]]) maxi++;
		if (Tree[i/2]==Tree[maxi] && maxi!=i) break;
		else Tree[i/2]=Tree[maxi];
		i/=2;
	}
}

int main()
{
	freopen("takmicenje2.in", "r", stdin);
	freopen("takmicenje2.out", "w", stdout);
	int n,k,i,t,a,b,time=0;
	niz[0]=-1;
	entryTime[0]=2000000000;
	scanf("%d %d", &n, &k);
	while (LastLevel<n) LastLevel*=2;
	for (i=1;i<=n;i++){
		scanf("%d", &niz[i]);
		Tree[LastLevel+i-1]=i;
		entryTime[i]=++time;
		ShuffleUp(LastLevel+i-1);
	}
	printf("%d\n", Tree[1]);
	while (k-->0){
		scanf("%d", &t);
		for (i=0;i<t;i++){
			scanf("%d %d", &a, &b);
			niz[a]=b;
			entryTime[a]=++time;
			ShuffleUp(LastLevel+a-1);
		}
		printf("%d\n", Tree[1]);
	}
	return 0;
}

