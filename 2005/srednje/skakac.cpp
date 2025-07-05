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

int a[200][200];
const int xd[]={-1,-2,1,2};
const int yd[]={-2,-1,-2,-1};
int n,m;
int main()
{
    for(int i=0;i<150;i++)for(int j=0;j<150;j++)a[i][j]=-(1<<29);
	scanf("%d %d",&n,&m);
	for(int i=2;i<=n+1;i++)
    {
        for(int j=2;j<=m+1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int maxio,rj=-(1<<29);
    for(int j=3;j<=m+1;j++)
    {
        for(int i=2;i<=n+1;i++)
        {
            maxio=-(1<<29);
            for(int k=0;k<4;k++)
            {
                maxio=max(maxio,a[i+xd[k]][j+yd[k]]);
            }
            a[i][j]=maxio+a[i][j];
            rj=max(rj,a[i][j]);
        }
    }
//    for(int i=2;i<=n+1;i++)
//    {
//        for(int j=2;j<=m+1;j++)
//        {
//            printf("%d ",a[i][j]);
//        }
//        puts("");
//    }
    printf("%d\n",rj);
    return 0;
}
/*
3 4
1 2 3 4
5 6 7 8
9 10 11 12
*/
