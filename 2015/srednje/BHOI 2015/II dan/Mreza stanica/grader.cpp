#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	void Stanice(int,int[],int);
	void PoveziStanice(int, int, int, int, int[], int[], int[], int[]);
	int UkupnaDuzina();
	
	int n,q,t,v,i,j,s1,s2;
	if(scanf("%d",&n)!=1)return 1;
	int *s=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
		if(scanf("%d",&s[i])!=1)return 1;
	if(scanf("%d",&q)!=1)return 1;
	Stanice(n,s,q);
	free(s);
	int *l,*a,*b,*c;
	for(i=0;i<q;i++)
	{
		if(scanf("%d %d %d %d",&s1,&s2,&t,&v)!=4)return 1;
		l=(int*)calloc(t,sizeof(int));
		for(j=0;j<t;j++)
			if(scanf("%d",&l[j])!=1)return 1;
		a=(int*)calloc(v,sizeof(int));
		b=(int*)calloc(v,sizeof(int));
		c=(int*)calloc(v,sizeof(int));
		for(j=0;j<v;j++)
			if(scanf("%d %d %d",&a[j],&b[j],&c[j])!=3)return 1;
		PoveziStanice(s1,s2,t,v,l,a,b,c);
		free(a);free(b);free(c);free(l);
	}
	printf("%d\n",UkupnaDuzina());
	return 0;
}
