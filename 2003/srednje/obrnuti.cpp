#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

char a[3][120],c;
int prbr=0,drbr=0;

int main()
{
    memset(a,0,sizeof a);
    while (isdigit(c=getchar()))
    {
          a[0][prbr++]=c-'0';
    }
    int jes=0;
    while (!isdigit(c=getchar()));
    a[1][drbr++]=c-'0';
    while (isdigit(c=getchar()))
    {
          a[1][drbr++]=c-'0';
    }
    int ost=0;
    for (int i=0;i<110;i++)
    {
        a[2][i]=(a[0][i]+a[1][i]+ost)%10;
        ost=(a[0][i]+a[1][i]+ost)/10;
    }
    for (int i=110;i>-1;i--)
    {
        if (a[2][i]==0 && !jes)continue;
        jes=i+1;break;
    }
    int jes1=0;
    for (int i=0;i<110;i++)
    {
        if (a[2][i]==0 && !jes1)continue;
        jes1=i;break;
    }
    for (int i=jes1;i<jes;i++)
    printf("%d",int(a[2][i]));
    if (jes1==jes)printf("0");
    printf("\n");
    return 0;    
}
