#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
 
using namespace std;
 
vector<vector<pair<int,int> > > ve;
int maxiD,maxiC;
void dfs(int x,int p,int d)
{
    if(d>maxiD)
    {
        maxiD=d;maxiC=x;
    }
    for(int i=0;i<ve[x].size();i++)
    {
        if(ve[x][i].first!=p)
            dfs(ve[x][i].first,x,d+ve[x][i].second);
    }
}
 
int Rasporedi(int N,int A[],int B[],int C[])
{
    ve.clear();ve.resize(N);
    for(int i=0;i<N-1;i++)
    {
        ve[A[i]-1].push_back(make_pair(B[i]-1,C[i]));
        ve[B[i]-1].push_back(make_pair(A[i]-1,C[i]));
    }
    /*
    for(int i=0;i<n;i++)
        dfs(i,-1,0);//brute force!!
    return maxiD;*/
    maxiC=0;maxiD=0;
    dfs(0,-1,0);
    int l=maxiC;
    maxiC=0;maxiD=0;
    dfs(l,-1,0);
    return maxiD;
}
