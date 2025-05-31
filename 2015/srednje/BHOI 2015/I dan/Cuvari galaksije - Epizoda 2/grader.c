#include <stdio.h>
#include <stdlib.h>

inline int get_int()
{
    static char z;
    int x=0;
    while((z=getchar())<'0');
    x=z-'0';
    while((z=getchar())>='0')x=x*10+z-'0';
    return x;
}

int main()
{
	void Rasporedi(int,int,int[],int[],int[]);
	int Zamijeni(int,int);
	int n,q,x,y;
	if(scanf("%d %d",&n,&q)!=2)return 0;
	int *a=(int*)calloc(n+5,sizeof(int));
	int *b=(int*)calloc(n+5,sizeof(int));
	int *c=(int*)calloc(n+5,sizeof(int));
	int i;
	for(i=0;i<n-1;i++)
		a[i]=get_int(),b[i]=get_int(),c[i]=get_int();
	Rasporedi(n,q,a,b,c);
	for(i=0;i<q;i++)
	{
		x=get_int();y=get_int();
		printf("%d ",Zamijeni(x,y));
	}
	free(a);free(b);free(c);
	return 0;
}
