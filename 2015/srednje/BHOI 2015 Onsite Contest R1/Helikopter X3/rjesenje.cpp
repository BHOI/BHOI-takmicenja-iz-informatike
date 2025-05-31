#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
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
typedef long long lint;
using namespace std;
const int INF=1<<30;
using namespace std;

class RMQ_tree
{
public:
    int n;
    int root;
    vector<int> f;
    RMQ_tree(){f.clear();n=-1;}
    RMQ_tree(vector<int> &a)
    {
        root=1;
        int log=(int)log2(a.size()+5)+1;
        int n=1<<(log+1);
        f.resize(n);
        napravi_drvo(root,0,(int)a.size(),a);
    }
    void konstruktor (vector<int> &a)
    {
        root=1;
        int log=(int)log2(a.size()+5)+1;
        int n=1<<(log+1);
        f.resize(n);
        napravi_drvo(root,0,(int)a.size(),a);
    }
    int napravi_drvo(int tr,int x,int y,vector<int> &a)
    {
        if(x>y)return INF;
        if(x==y){f[tr]=a[x];return f[tr];}
        int mid=(x+y)/2;
        return f[tr]=min(napravi_drvo(2*tr,x,mid,a),napravi_drvo(2*tr+1,mid+1,y,a));
    }
    int minimum(int x,int y,int vel)
    {
        return rt_m(root,0,vel,x,y);
    }
    int rt_m(int tr,int x,int y,int a,int b)
    {
        if(x>y)return INF;
        if(a<=x && y<=b)return f[tr];
        if(y<a || x>b)return INF;
        int mid=(x+y)/2;
        return min(rt_m(2*tr,x,mid,a,b),rt_m(2*tr+1,mid+1,y,a,b));
    }
    void oslobodi(){f.clear();}
};

int rijesi_dp_brutalno(vector<vector<int> > mat)
{
    int n=mat.size(),m=mat[0].size();
    vector<vector<int> > dp(n,vector<int>(m,INF));
    for(int i=0;i<n;i++)mat[i][m-1]=INF;
    mat[n-1][m-1]=0;
    dp[n-1][m-1]=0;
    for(int j=m-2;j>=0;j--)
    {
            for(int i=0;i<n;i++)
            {
                    if(mat[i][j]==-1)dp[i][j]=INF;
                    for(int k=min(i+mat[i][j],n-1);k>=max(i-mat[i][j],0);k--)
                    {
                            dp[i][j]=min(dp[i][j],mat[i][j]+dp[k][j+1]);
                    }
            }
    }
    cout<<"Brutalno je: "<<dp[n-1][0]<<endl;
    return (dp[n-1][0]!=INF)?dp[n-1][0]:-1;
}

int rijesi(vector<vector<int> > mat)
{
   int n=mat.size(),m=mat[0].size();
   vector<int> dp(n,INF);//not fail safe INF
   dp[n-1]=0;
   RMQ_tree tree;
   for(int j=m-2;j>=0;j--)
   {
       tree.konstruktor(dp);
       for(int i=0;i<n;i++)
       {
            if(mat[i][j]==-1)dp[i]=INF;
            else dp[i]=min(mat[i][j]+tree.minimum(max(0,i-mat[i][j]),min(i+mat[i][j],n-1),n),INF);
       }
   }
   return (dp[n-1]!=INF)?dp[n-1]:-1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<int> > mat(n,vector<int>(m,INF));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    printf("%d\n",rijesi(mat));
    return 0;
}
