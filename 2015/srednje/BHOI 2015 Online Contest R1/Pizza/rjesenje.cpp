#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
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

int rj1(int n,vector<int> a)
{
    set<pair<int,int> > st,nst;
    sort(a.begin(),a.end());
    st.insert(mp(a[0],0));
    set<pair<int,int> >::iterator it;
    int dos=a[0],niz[5]={0};
    for(int i=0;i<n;i++)
    {
        niz[0]+=a[i];
        sort(niz,niz+3);
    }
    int maxim=niz[2];
    for(int i=1;i<n;i++)
    {
        dos+=a[i];
        for(it=st.begin();it!=st.end();++it)
        {
            niz[0]=it->xx;niz[1]=it->yy;
            niz[2]=dos-niz[0]-niz[1];
            sort(niz,niz+3);
            if(niz[2]<=maxim)nst.insert(mp(niz[2],niz[1]));
            niz[0]=it->xx+a[i];niz[1]=it->yy;
            niz[2]=dos-niz[0]-niz[1];
            sort(niz,niz+3);
            if(niz[2]<=maxim)nst.insert(mp(niz[2],niz[1]));
            niz[0]=it->xx;niz[1]=it->yy+a[i];
            niz[2]=dos-niz[0]-niz[1];
            sort(niz,niz+3);
            if(niz[2]<=maxim)nst.insert(mp(niz[2],niz[1]));
        }
        st=nst;
        nst.clear();
    }
    return st.begin()->xx;
}

int rj2(int n,vector<int> a)
{
    vector<vector<vector<bool> > > dp;
    dp.assign(2,vector<vector<bool> >(1101,vector<bool>(1101,0)));
    dp[0][0][0]=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        for(int j=0;j<1100;j++)
        {
            for(int k=0;k<1100;k++)
            {
                if(dp[i&1][j][k])
                {
                    if(j+a[i]<1100)
                    {
                        dp[(i+1)&1][j+a[i]][k]=1;
                        dp[(i+1)&1][k][j+a[i]]=1;
                    }
                    if(k+a[i]<1100)
                    {
                        dp[(i+1)&1][j][k+a[i]]=1;
                        dp[(i+1)&1][k+a[i]][j]=1;
                    }
                    dp[(i+1)&1][k][j]=1;
                    dp[(i+1)&1][j][k]=1;
                    //printf("%d %d %d\n",i,j,k);
                }
            }
        }
    }
    for(int i=0;i<1100;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(sum-i-j>i)continue;
            if(dp[n&1][i][j])return i;
        }
    }
    return -1;
}

int greed1(int n,vector<int> a)
{
    int niz[3]={0};
    for(int i=0;i<n;i++)
    {
        niz[0]+=a[i];
        sort(niz,niz+3);
    }
    return niz[2];
}

int brut1(int n,vector<int> a)
{
    clock_t POC=clock();
    vector<int> stp3;
    stp3.pb(1);
    for(int i=1;stp3[i-1]<50000000/3;i++)
        stp3.pb(stp3[i-1]*3);
    if(n>=(int)stp3.size()-1)return -1;
    int minio=30000;
    for(int i=0;i<stp3[n];i++)
    {
        int niz[3]={0};
        for(int j=n-1;j>=0;j--)
        {
            niz[(i%stp3[j+1])/stp3[j]]+=a[j];
        }
        sort(niz,niz+3);
        minio=min(minio,niz[2]);
        if((double)(clock()-POC)/CLOCKS_PER_SEC>1.5)return -1;
    }
    return minio;
}

int main()
{
    int n;
    vector<int> p;
    scanf("%d",&n);
    p.resize(n);
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
    printf("%d\n",rj1(n,p));
    return 0;
}
