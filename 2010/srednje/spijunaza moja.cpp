#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int x,y,duz;
    edge(int _x=0,int _y=0,int _duz=0){x=_x;y=_y;duz=_duz;}
    inline bool operator< (const edge &ppp)const{return duz<ppp.duz;}
};

int n,m,k,un[1000005],c,a,b;
unsigned long long int uuu;
vector <edge> vv;

inline int findp(int x)
{
    return (x==un[x])?x:(un[x]=findp(un[x]));
}

inline void setp (int a,int b)
{
    un[findp(a)]=un[findp(b)];
}

int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<n;i++)
    {
        un[i]=i;
    }
    for (int i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        setp(a,b);
    }
    vv.resize(k);
    for (int i=0;i<k;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        vv[i]=edge(a,b,c);
    }
    uuu=0;
    sort(vv.begin(),vv.end());
    for (int i=0;i<k;i++)
    {
        if (findp(vv[i].x)!=findp(vv[i].y))
        {setp(vv[i].x,vv[i].y);uuu+=(unsigned long long)vv[i].duz;}
    }
    printf("%llu\n",uuu);
    return 0;
}
