#include <stdio.h>
#include <stdlib.h>
int main()
{
	int Rasporedi(int,int[],int[],int[]);
	int n;
	if(scanf("%d",&n)!=1)return 0;
	int *a=(int*)calloc(n+5,sizeof(int));
	int *b=(int*)calloc(n+5,sizeof(int));
	int *c=(int*)calloc(n+5,sizeof(int));
	for(int i=0;i<n-1;i++)
		if(scanf("%d %d %d",&a[i],&b[i],&c[i])!=3)return 0;
	printf("%d\n",Rasporedi(n,a,b,c));
	free(a);free(b);free(c);
	return 0;
}
