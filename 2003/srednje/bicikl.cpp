#include <cstdio>
#include <queue>

using namespace std;

struct nes
{
       int v,x,y;
       /*bool operator< (const nes &a)const
       {
            return (a.v>v);
       }*/
}tmp;

int a[20005],n,maxs=0,maxi=0,maxj=0,sum;
nes cuvaj;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n-1;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n-1;i++)
    {
        if (a[i]>0)
        {
                   cuvaj.v=0;
                   sum=0;
                   for (int j=i;j<n-1;j++)
                   {
                       sum+=a[j];
                       if (sum>=cuvaj.v)
                       {
                       tmp.v=sum;tmp.x=i+1;tmp.y=j+2;
                       cuvaj=tmp;
                       }
                   }
                   tmp=cuvaj;
                   if (tmp.v>maxs || (tmp.v==maxs && (maxj-maxi<tmp.y-tmp.x)))
                   {
                                      maxi=tmp.x;
                                      maxj=tmp.y;
                                      maxs=tmp.v;
                   }
        }
    }
    if (maxs==0)printf("NEMA");
    else printf("%d %d\n",maxi,maxj);
    system("pause");
    return 0;
}
