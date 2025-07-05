#include <cstdio>
#include <algorithm>
using namespace std;

int a,b,x[105][105];
int mink[105],maxr[105];

int main()
{
    memset(x,0,sizeof x);
    memset(mink,0,sizeof mink);
    memset(maxr,0,sizeof maxr);
    scanf("%d %d",&a,&b);
    for (int j=0;j<b;j++)mink[j]=1<<30;
    for (int i=0;i<a;i++)maxr[i]=-1<<30;
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++)
        {
            scanf("%d",&x[i][j]);
            if (j)mink[j]=min(mink[j],x[i][j]);else mink[j]=x[i][j];
            maxr[i]=max(maxr[i],x[i][j]);
        }
    }
    for (int i=0;i<a;i++)
    for (int j=0;j<b;j++)
    {
        if (maxr[i]==mink[j])printf("%d %d %d\n",x[i][j],i+1,j+1);
    }
    scanf("%d",&a);
    return 0;
}
