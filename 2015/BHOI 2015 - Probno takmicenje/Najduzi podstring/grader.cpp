#include <stdio.h>
#include <stdlib.h>

int main()
{
	int NajduziPodstring(int,int,int*,int*);
	int n=0,k,i;
	int *a=(int*)malloc(sizeof(int)*1000005);
	scanf("%d",&k);
	while(scanf("%d",&a[n]) && a[n++]!=-1);
	n--;
	int *izlaz=(int*)malloc(sizeof(int)*n);
	int duz=NajduziPodstring(n,k,a,izlaz);
	printf("%d\n",duz);
	for(i=0;i<duz;i++)printf("%d\n",izlaz[i]);
	free(izlaz);
	free(a);
	return 0;
}
