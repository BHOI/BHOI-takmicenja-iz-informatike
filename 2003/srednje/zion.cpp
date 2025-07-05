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
int n,k,a;
vector<int> ve;
int main()
{
    freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&k);ve.resize(k);
	for(int i=0;i<k;i++)scanf("%d",&ve[i]);
	for(int i=0;i<n-k;i++)
    {
        scanf("%d",&a);
        int minp=0,mink=abs(ve[0]-a);
        for(int i=1;i<ve.size();i++)
        {
            if(abs(ve[i-1]-a)+abs(ve[i]-a)-abs(ve[i-1]-ve[i])<mink)
            {
                mink=abs(ve[i-1]-a)+abs(ve[i]-a)-abs(ve[i-1]-ve[i]);
                minp=i;
            }
        }
        if(abs(ve.back()-a)<mink){minp=ve.size();}
        ve.insert(ve.begin()+minp,a);
    }
   // for(int i=0;i<ve.size();i++)printf("%d ",ve[i]);
    int sum=0;
    for(int i=1;i<ve.size();i++)
    {
        sum+=abs(ve[i]-ve[i-1]);
    }
    printf("%d\n",sum);
   // scanf("%d",&sum);
    return 0;
}
