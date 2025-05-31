#include <cstdio>

extern int pogodi();

typedef unsigned long long llu;

static llu SSB=10;
static int brojPoziva=0;
static llu zamisljeniBroj;

int SSF()
{
    if(brojPoziva>SSB)return 0;
    else return 1;
}

int ovajBroj(llu X)
{
	brojPoziva++;
    if(zamisljeniBroj>X)return -1;
    if(zamisljeniBroj==X)return 0;
    if(zamisljeniBroj<X)return 1;
}

int main()
{
    zamisljeniBroj=5;
    if(pogodi()==5)printf("Pogodjeno sa %d %d\n",brojPoziva,SSF());
    return 0;
}
