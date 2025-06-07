#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct faktor{
    int broj;
    int kolicina;
    faktor() {}
    faktor (int b, int k)
    {
        broj=b; kolicina=k;
    }
} fakt[40000];
bool poredi (faktor a, faktor b)
{
    if (a.kolicina > b.kolicina) return true;
    else if (a.kolicina == b. kolicina)
    {
        if (a.broj > b.broj) return true;
        return false;
    }
    return false;
}
bool je_li_prost (int n)
{
    int i;
    if (n==1) return false;
    else if (n==2) return true;
    else if (n%2==0) return false;
    int korijen=(int)sqrt(n);
    for (i=3; i<=korijen; i+=2) if (n%i==0) return false;
    return true;
}
int main()
{
    int i,j,n,nums[10000],prosti[38000],kol[100050],brp=1,p,tmp,z=0;
    bool prostq[100050]={};

    freopen("faktori.in","r",stdin);
    freopen("faktori.out","w",stdout);

    prosti[0]=2; prostq[2]=true;
    for (i=3; i<100000; i+=2) if(je_li_prost(i)) { prosti[brp++]=i; prostq[i]=true; }

    scanf("%d",&n);

    for (i=0; i<n; i++)
    {
        scanf("%d",&nums[i]);
        if (prostq[nums[i]]) kol[nums[i]]++;
        else
        {
        tmp=nums[i];
        for (j=0; j<brp && prosti[j]<nums[i]; j++)
        {
            while(tmp%prosti[j]==0) { tmp/=prosti[j]; kol[prosti[j]]++; }
        }
        }
    }

    if (kol[2]>0) fakt[z++]=faktor(2,kol[2]);
    for (i=3; i<100000; i+=2) if (kol[i]>0) fakt[z++]=faktor(i,kol[i]);

    sort(fakt,fakt+z,poredi);

    printf("%d\n",z);
    for (i=0; i<z; i++) printf("%d %d\n",fakt[i].broj,fakt[i].kolicina);


    return 0;
}
