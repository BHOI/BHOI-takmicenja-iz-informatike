#include <cstdio>
#include <queue>
#include <vector>
#include <math.h>
#include <cstring>
using namespace std;

struct edge
{
       int doi;
       double duz;
       bool operator < (const edge &pp)const
       {
            return (pp.duz<duz);
       }
       edge(){}
       edge (int doo,double duzz)
       {
            doi=doo;duz=duzz;
       }
};

vector <edge> l[101];
priority_queue <edge> p;
int n,a[101],b[101];
double dzn;
bool vis[101];

double prim (int x)
{
       edge tmp;double sum=0.000;int br=1;
       for (int i=0;i<l[x].size();i++)p.push(l[x][i]);
       vis[x]=1;
       while (!p.empty())
       {
             tmp=p.top();p.pop();
             if (!vis[tmp.doi])
             {
                               sum+=tmp.duz;
                         for (int i=0;i<l[tmp.doi].size();i++)p.push(l[tmp.doi][i]);
                         vis[tmp.doi]=1;       br++; if (br==n)return sum;
             }
       }
       return sum;
}

int main()
{
    memset(vis,0,sizeof vis);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }    
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            dzn=sqrt(double((a[i]-a[j]))*(a[i]-a[j])+double((b[i]-b[j]))*(b[i]-b[j]));
            l[i].push_back(edge(j,dzn));
            l[j].push_back(edge(i,dzn));
        }
    }
    printf("%.2lf\n",prim(0));    
    return 0;
}
