int Odmor(int n,int a[])
{
	int krece=500,i;
	int rez=0;
	for(i=0;i<n;krece=a[i++])
		if(a[i]!=krece)rez+=3;
	if(krece!=0)rez+=3;
	return rez;
}
