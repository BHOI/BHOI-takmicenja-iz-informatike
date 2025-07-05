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
const int inf=1<<29;
int tab[1<<17];
vector<int> a;
queue<pair<int,int> > kju;
int n,m,k,tmp;
int unsbi()
{
    char c;
    int rez=0;
    for(int i=n-1;i>=0;i--)
    {
        scanf(" %c",&c);
        rez+=(c=='1')*(1<<i);
    }
    return rez;
}
void bfs()
{
    kju.push(mp(0,0));
    pair<int,int> tmp;
    while(!kju.empty())
    {
        tmp=kju.front();kju.pop();
        for(int i=0;i<m;i++)
        {
            if(tab[a[i]^tmp.xx]==-1)
            {
                tab[a[i]^tmp.xx]=tmp.yy+1;
                kju.push(mp(a[i]^tmp.xx,tmp.yy+1));
            }
        }
    }
}
int cntb(int x)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(x&(1<<i))c++;
    }
    return c;
}
int main()
{
    memset(tab,-1,sizeof tab);
	scanf("%d %d",&m,&n);
	a.resize(m);
	k=unsbi();
	//for(int i=0;i<(1<<17)-5;i++)tab[i]=inf;
	for(int i=0;i<m;i++)    a[i]=unsbi();
    bfs();
    int maxio=n,maxv;
    for(int i=0;i<(1<<n);i++)
    {
        if(tab[i]!=-1 && cntb(i^k)<maxio)
        {
            maxio=cntb(i^k);
            maxv=tab[i];
        }
    }
    printf("%d %d\n",maxv,n-maxio);
    return 0;
}
