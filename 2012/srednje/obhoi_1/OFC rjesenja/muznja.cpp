#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct tacka
{
       int v;
       bool p;
       bool operator< (const tacka &xx) const
       {
            return (v!=xx.v)?v<xx.v:p>xx.p;
       }
};

int main()
{
freopen("muznja.in","r",stdin);
freopen("muznja.out","w",stdout);
    int n;
    scanf("%d",&n);
    
    tacka a[2*n+5];
    
    for(int i=0;i<2*n;i+=2)
    {
            scanf("%d %d",&a[i].v,&a[i+1].v);
            a[i].p=1;
            a[i+1].p=0;
    }
       
    sort(a,a+2*n);
    
    int b=1,rj1=0,rj2=0;
    
    int pocetak=a[0].v;
    
    for(int i=1;i<2*n;i++)
    {
            if(a[i].p) b++;
            else
            { 
                b--;
            
                if(!b)
                {
                      rj1=max(rj1,a[i].v-pocetak);
                      pocetak=a[i+1].v;
                      if(i<2*n-1)
                      rj2=max(rj2,a[i+1].v-a[i].v);
                }
            }
            
            
    }
    cout<<rj1<<" "<<rj2<<endl;
    return 0;
}
            
