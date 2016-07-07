#include <cstdlib>
#include <cstdio>

extern void init(int,int,int);
static int pH,pL,op,n;

static void zavrsi(int x,int z)
{
   if(z==op && x==1)
        printf("BRAVO1\n");
   else
   {
        printf("NEBRAVO0\n");
        exit(0);
   }
}

int inPogodi(int x)
{
    static int veceod=0,manjeod=n+1;
    if(manjeod-veceod==2 && x==manjeod-1)
    {
        zavrsi(1,op);
        return 0;
    }
    if(x<=veceod)
    {
        if(pH==0)
            zavrsi(0,op);
        pH--;
        return 1;
    }
    if(x>=manjeod)
    {
        if(pL==0)
            zavrsi(0,op);
        pL--;
        return -1;
    }
    if(manjeod-x>x-veceod)
    {
        veceod=x;
        if(pH==0)
            zavrsi(0,op);
        pH--;
        return 1;
    }
    else
    {
        manjeod=x;
        if(pL==0)
            zavrsi(0,op);
        pL--;
        return -1;
    }
    return 5;
}

int pogodi(int x)
{
    if(op==-1)return inPogodi(x);
    if(op>x)
    {
        if(pH==0)
            zavrsi(0,op);
        pH--;
        return 1;
    }
    if(op<x)
    {
        if(pL==0)
            zavrsi(0,op);
        pL--;
        return -1;
    }
    if(op==x)
    {
        zavrsi(1,op);
        return 0;
    }
    return 5;
}


int main()
{
	scanf("%d %d %d %d",&n,&pL,&pH,&op);
	//kada je op==-1 poziva najtezu strategiju
    init(n,pL,pH);
    return 0;
}
