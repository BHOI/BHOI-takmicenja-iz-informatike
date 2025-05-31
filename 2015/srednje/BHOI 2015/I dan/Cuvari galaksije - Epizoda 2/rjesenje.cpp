#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;
const int maxn=100005;
const int maxp=19;
int P[maxn][maxp];
int lvl[maxn];
long long D[maxn][maxp];
vector<vector<pair<int,int> > > ve;
vector<int> zamj;

pair<long long,bool> brute(int x,int p,int y)
{
    if(x==y)return mp(0,1);
    pair<long long,bool> tmp;
    long long rez=0;
    bool da=0;
    for(int i=0;i<(int)ve[x].size();i++)
    {
        if(ve[x][i].xx==p)continue;
        tmp=brute(ve[x][i].xx,x,y);
        if(tmp.yy==0)continue;
        da=1;
        rez+=tmp.xx+ve[x][i].yy;
    }
    return mp(rez,da);
}

pair<long long,int> dfs(int x,int p,int l=0)
{
    lvl[x]=l;
    long long rez=0;
    int br=1;
    pair<long long,int> tmp;
    for(int i=0;i<(int)ve[x].size();i++)
    {
        if(ve[x][i].xx==p)continue;
        tmp=dfs(ve[x][i].xx,x,l+1);
        P[ve[x][i].xx][0]=x;
        D[ve[x][i].xx][0]=ve[x][i].yy;
        rez+=tmp.xx+tmp.yy*ve[x][i].yy;
        br+=tmp.yy;
    }
    //printf("\n%d %d %d\n",x,rez,br);
    return mp(rez,br);
}

int Zamijeni(int x,int y)
{
    x--;y--;
    long long rez=0;

    swap(zamj[x],zamj[y]);
    x=zamj[x];y=zamj[y];

    if(lvl[x]<lvl[y])std::swap(x,y);
    //printf("\nP%d %d %d %d\n",lvl[x],lvl[y],x,y);
    int z=maxp-1;
    while(lvl[x]>lvl[y])
    {
        if(lvl[x]-lvl[y]>=(1<<z))
        {
            rez+=D[x][z];
            x=P[x][z];
        }
        z--;
    }
    if(x==y)return rez;
    for(int i=maxp-1;i>=0;i--)
    {
        if(P[x][i]!=P[y][i])
        {
            rez+=D[x][i]+D[y][i];
            x=P[x][i];y=P[y][i];
        }
    }
    rez+=D[x][0]+D[y][0];
    if(P[x][0]!=P[y][0])throw;
    return rez;
}

void Rasporedi(int n,int q,int a[],int b[],int c[])
{
    memset(P,-1,sizeof P);
    memset(D,0,sizeof D);
    memset(lvl,0,sizeof lvl);
    ve.clear();
    ve.resize(n);zamj.resize(n);
    for(int i=0;i<n;i++)zamj[i]=i;
    for(int i=0;i<n-1;i++)
    {
        a[i]--;b[i]--;
        ve[a[i]].pb(mp(b[i],c[i]));
        ve[b[i]].pb(mp(a[i],c[i]));
    }
    dfs(0,-1);
    //preprocess the LCA
    for(int j=1;j<maxp;j++)
    {
        for(int i=1;i<n;i++)
        {
            if(P[i][j-1]==-1 || P[P[i][j-1]][j-1]==-1)continue;
            P[i][j]=P[P[i][j-1]][j-1];
            D[i][j]=D[P[i][j-1]][j-1]+D[i][j-1];
        }
    }
    return;
}

