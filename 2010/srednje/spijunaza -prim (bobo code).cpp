#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct edge 
{
       int duz;
       int doj;
       bool operator < (const edge &a)const
       {
            return (a.duz<duz);
       }
       edge(){}
       edge (int _a,int _b){duz=_a;doj=_b;}
};

priority_queue<edge> p;
vector<edge> a[1000002];
bool vis[1000002];
int n,k,m,x,y,z;

unsigned long long int prim ()
{
         unsigned long long int kraj=0;
         int kolko=1,pp=a[1].size();
         for (int i=0;i<pp;i++)
         p.push(a[1][i]);vis[1]=1;
         edge tmp;
         while (!p.empty())
         {
               tmp=p.top();p.pop();
               if (!vis[tmp.doj])
               {
                                 kolko++;
                                 vis[tmp.doj]=1;
                                 kraj+=tmp.duz;
                                 pp=a[tmp.doj].size();
                                 for (int i=0;i<pp;i++)
                                 {
                                     p.push(a[tmp.doj][i]);
                                 }
               }
               if (kolko>n)break;
         }
         return kraj;
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    memset(vis,0,sizeof vis);
    scanf("%d %d %d",&n,&k,&m);
    for (int i=0;i<k;i++)
    {
        scanf("%d %d",&x,&y);
        a[x].push_back(edge(0,y));
        a[y].push_back(edge(0,x));
    }
    for (int i=0;i<m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        a[x].push_back(edge(z,y));
        a[y].push_back(edge(z,x));
    }
    printf("%llu\n",prim());
    return 0;
}
