#include <bits/stdc++.h>

extern unsigned long long pogodi();

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
    if(zamisljeniBroj>X)return -1;
    if(zamisljeniBroj==X)return 0;
    if(zamisljeniBroj<X)return 1;
}

int main()
{
    scanf("%llu %llu",zamisljeniBroj,SSB);
    if(pogodi()==zamisljeniBroj && brojPoziva<SSB)printf("NIKADPOGODITI1");
    else printf("NIKADPOGODITI0");
    return 0;
}
