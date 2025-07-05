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
vector<vector<int> > a,_tmp;
vector<vector<bool> >vis;
const int xd[]={0,-1,0,1};
queue<pair<int,int> > kju;
const int yd[]={-1,0,1,0};
int n,m;
int bfs(pair<int,int> f)
{
    while (!kju.empty())kju.pop();
    kju.push(f);
    int c=0;
    pair<int,int> tmp;
    vis[f.xx][f.yy]=1;
    while (!kju.empty())
    {
        tmp=kju.front();kju.pop();
        c++;
        for(int i=0;i<4;i++)
        {
            if(!(a[tmp.xx][tmp.yy]&(1<<i)) && !vis[tmp.xx+xd[i]][tmp.yy+yd[i]])
            {
                kju.push(mp(tmp.xx+xd[i],tmp.yy+yd[i]));
                vis[tmp.xx+xd[i]][tmp.yy+yd[i]]=1;
            }
        }
    }
    return c;
}

int main()
{
    //freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&m);
	a.resize(n,vector<int>(m));
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            if(i==0)a[i][j]|=2;
            if(j==0)a[i][j]|=1;
            if(i==n-1)a[i][j]|=8;
            if(j==m-1)a[i][j]|=4;
        }
    }
    _tmp=a;
    int lmaxio,maxio=-1<<29;
    pair<pair<int,int>,int> pot;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<4;k++)
            {
               if((a[i][j]&(1<<k)) && i+xd[k]>=0 && j+yd[k]>=0 && i+xd[k]<n && j+yd[k]<m)
               {
                    a[i][j]^=(1<<k);
                    a[i+xd[k]][j+yd[k]]^=(1<<((k+2)%4));
                    vis.assign(n,vector<bool>(m,0));
                    lmaxio=0;
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<m;j++)
                        {
                            if(!vis[i][j])
                            lmaxio=max(lmaxio,bfs(mp(i,j)));
                        }
                    }
                    if(lmaxio>maxio){pot.xx.xx=i;pot.xx.yy=j;pot.yy=k;maxio=lmaxio;}
                    a[i][j]^=(1<<k);
                    a[i+xd[k]][j+yd[k]]^=(1<<((k+2)%4));
                }
            }
        }
    }
    printf("%d %d %d\n",pot.xx.xx+1,pot.xx.yy+1,1<<pot.yy);
    return 0;
}
