#include <stdio.h>
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
	int koliko(int,int);
	void pravi(int);
    static int usao=0;
    usao++;
    if(usao>1)return 0;
    int n;
    n=get_int();
    pravi(n);
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        a=get_int();b=get_int();
        printf("%d\n",koliko(a,b));
    }
    return 0;
}
