void nadji_slova(int n, int a[],int b[])
{
	int i;
	for(i=0;i<n;i++)b[i]=!(a[i]<0x20);
}
