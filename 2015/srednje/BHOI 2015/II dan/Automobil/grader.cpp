#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int Odmor(int,int[]);
	int T;
	if(scanf("%d",&T)!=1)return 0;
	int nMax=10000000,nMin=8000000;
	if(T<17){nMin=100000;}
	if(T<15){nMax=10000;nMin=100;}
	if(T<10){nMax=1000;nMin=5;}
	srand(T+100);
	int n=(rand()%(nMax-nMin)+nMin);
	int *a=(int*)calloc(n,sizeof(int));
	int i;
	int odgovor=0,zadnji=500;
	for(i=0;i<n;i++)
	{
		a[i]=rand()%9000;
		if(zadnji!=a[i])odgovor+=3;
		zadnji=a[i];
	}
	if(zadnji!=0)odgovor+=3;
	if(Odmor(n,a)==odgovor)printf("==TACNO==");
	else printf("--NETACNO--");
	free(a);
	return 0;
}
