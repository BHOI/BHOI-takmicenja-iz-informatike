#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct edge
{
       int poc,kra;
       int duz;
       edge (){}
       edge (int _p,int _k,int _d)
       {
            poc=_p;kra=_k;duz=_d;
       }
       bool operator < (const edge &o)const
       {
            return (o.duz>duz);
       }
};

int n,x[120],y[120];
vector <edge> a;
int boje[120];

int main()
{
    for (int i=0;i<102;i++)boje[i]=i;
    scanf("%d",&n);
    for (int i=0;i<n;i++)scanf("%d %d",&x[i],&y[i]);
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            a.push_back(edge(i,j,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
        }
    }
    sort (a.begin(),a.end());
    int broj=0,tren=0,iz,u;
    double duzinau=0.000;
    while (true)
    {
          if (broj==n-1)break;
          iz=boje[a[tren].poc];u=boje[a[tren].kra];
          if (iz!=u)
          {
                    for (int i=0;i<102;i++)if (boje[i]==iz)boje[i]=u;
                    duzinau+=double(sqrt(double(a[tren].duz)));
                    broj++;
          }
          tren++;
    }
    printf("%.2lf\n",duzinau);
    system("pause");
    return 0;
}
