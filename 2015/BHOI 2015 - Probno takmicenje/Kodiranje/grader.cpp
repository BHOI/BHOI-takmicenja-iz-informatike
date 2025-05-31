#include <stdio.h>

int main()
{
	void nadji_slova(int,int[],int[]);
	int n;
	scanf("%d",&n);
	int a[300],b[300],i;
	for(i=0;i<n;i++)
		scanf("%X",&a[i]);
	nadji_slova(n,a,b);
	for(i=0;i<n;i++)
		printf("%c",(b[i]==0)?'.':((b[i]==1)?'-':'*'));
	return 0;
}
