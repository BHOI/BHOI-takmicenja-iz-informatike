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
vector<vector<vector<int> > > ve;
int n,m,k,l,a,b,s,e,r;
int dp[2][600];
int main()
{
	scanf("%d %d %d %d %d %d",&n,&m,&k,&l,&a,&b);
	ve.resize(n,vector<vector<int> >(k));
	for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&s,&e,&r);
        ve[s][r].pb(e);
    }
    memset(dp,0,sizeof dp);
    dp[0][a]=1;
    bool da=0;
    while(l--)
    {
        scanf("%d",&r);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<ve[i][r].size();j++)
            {
                dp[1][ve[i][r][j]]+=dp[0][i];
                if(dp[1][ve[i][r][j]]>=1000000){da=1;dp[1][ve[i][r][j]]%=1000000;}
            }
        }
        for(int i=0;i<n;i++){dp[0][i]=dp[1][i];dp[1][i]=0;}
    }
    if(da)
    printf("%06d\n",dp[0][b]);
    else printf("%d\n",dp[0][b]);
    return 0;
}
