#include <cstdio>

int Odmor(int n,int a[])
{
	int krece=500,i;
	int rez=0;
	for(i=0;i<n;krece=a[i++])
		if(a[i]!=krece)rez+=3;
	if(krece!=0)rez+=3;
	return rez;
}
int a[1000005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",Odmor(n,a));
	return 0;
}

