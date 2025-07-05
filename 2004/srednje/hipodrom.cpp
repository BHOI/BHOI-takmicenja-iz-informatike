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

typedef pair<int,int> ii;
ii p,k,r;
queue<pair<ii,int> > kju;
int n,h,x,hh;
int a[200][200];
int vis[200][200];
const int xd[]={-2,-2,-1,-1,1,1,2,2};
const int yd[]={-1,1,-2,2,2,-2,1,-1};
const int je[]={1,0,1,0,1,0,1,0};
int moze(ii st,ii en,int k)
{
    if(a[en.xx][en.yy])return 0;
    int vr[2]={1,1},yes=0;
    for(int i=min(st.xx,en.xx);i<=max(st.xx,en.xx);i++)
    {
        for(int j=min(st.yy,en.yy);j<=max(st.yy,en.yy);j++)
        {
			if((je[k])?(i-min(st.xx,en.xx)):(max(st.xx,en.xx)-i)==2)yes=1;
			if(j-min(st.yy,en.yy)==2)yes=0;
            
        }
    }
	//if(a[i][j]>h)vr[(je[k])?(i-min(st.xx,en.xx)):(max(st.xx,en.xx)-i)>=j-min(st.yy,en.yy)]=0;
	for(int i=min(st.xx,en.xx);i<=max(st.xx,en.xx);i++)
    {
        for(int j=min(st.yy,en.yy);j<=max(st.yy,en.yy);j++)
        {
			int o=(je[k])?(i-min(st.xx,en.xx)):(max(st.xx,en.xx)-i);
			int u=j-min(st.yy,en.yy);
			if(a[i][j]<=h)continue;
			if(yes)
			{
				if(o>u)vr[0]=0;
				else vr[1]=0;
			}
			else 
			{
				if(o<u)vr[1]=0;
				else vr[0]=0;
			}
        }
    }
    return vr[0]||vr[1];
}
void bfs(ii start)
{
    while (!kju.empty())kju.pop();
    kju.push(mp(mp(start.xx,start.yy),0));
    vis[start.xx][start.yy]=0;
    pair<ii,int> tmp;
    while (!kju.empty())
    {
        tmp=kju.front();
        kju.pop();
        for(int i=0;i<8;i++)
        {
            if(vis[tmp.xx.xx+xd[i]][tmp.xx.yy+yd[i]]==-1 && moze(tmp.xx,mp(tmp.xx.xx+xd[i],tmp.xx.yy+yd[i]),i))
            {
                kju.push(mp(mp(tmp.xx.xx+xd[i],tmp.xx.yy+yd[i]),tmp.yy+1));
                vis[tmp.xx.xx+xd[i]][tmp.xx.yy+yd[i]]=tmp.yy+1;
            }
        }
    }
}
int main()
{
	scanf("%d %d %d %d %d %d %d",&n,&h,&x,&p.xx,&p.yy,&k.xx,&k.yy);
	p.xx+=2;p.yy+=2;k.yy+=2;k.xx+=2;
	memset(a,-1,sizeof a);
	for(int i=3;i<n+3;i++)
        for(int j=3;j<n+3;j++)a[i][j]=0;
	for(int i=0;i<x;i++)
    {
        scanf("%d %d %d",&r.xx,&r.yy,&hh);
        r.xx+=2;r.yy+=2;
        a[r.xx][r.yy]=hh;
    }
    memset(vis,-1,sizeof vis);
    bfs(p);
    printf("%d\n",vis[k.xx][k.yy]!=-1?vis[k.xx][k.yy]:0);
    return 0;
}
