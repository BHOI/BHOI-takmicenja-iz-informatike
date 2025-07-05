#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct nov 
{
       int vr;
       char oz;
       nov(){}
       nov (int _p,char _y)
       {oz=_y;vr=_p;}
       bool operator < (const nov &o)const
       {
            return (o.vr<vr);
       }
};

int aa,m,n;
char x;
vector <nov> p;
vector <nov> a[15100];

int main()
{
    scanf("%d %d\n",&n,&m);
    for (int i=0;i<n;i++)
    {
        scanf("%c %d\n",&x,&aa);
        
        p.push_back(nov(aa,x));
        a[aa].push_back(nov(aa,x));
    }
    sort(p.begin(),p.end());
    for (int i=0;i<m+1;i++)
    {
        if (a[i].size())
        for (int j=0;j<n;j++)
        {
            if (i+p[j].vr>m)continue;
            if (a[i+p[j].vr].size())
            {
                                 if (a[i+p[j].vr].size()>1+a[i].size())
                                 {  
                                                                a[i+p[j].vr]=a[i];
                                                                a[i+p[j].vr].push_back(nov(p[j].vr,p[j].oz));
                                 }  
                                 else 
                                 {
                                      if (a[i+p[j].vr].size()==1+a[i].size())
                                      {
                                      }
                                 }
            }
            else 
            {
                 a[i+p[j].vr]=a[i];
                 a[i+p[j].vr].push_back(nov(p[j].vr,p[j].oz));
            }
        }
    }
    if (a[m].size())
    {
                    sort(a[m].begin(),a[m].end());
                    for (int i=0;i<a[m].size();i++)
                    printf("%c",a[m][i].oz);
    }
    else printf("Q");
    printf("\n");
    return 0;
}
