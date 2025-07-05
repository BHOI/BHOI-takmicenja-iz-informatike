#include <cstdio>

using namespace std;
int s,n;

int main()
{
    scanf("%d %d",&n,&s);
    if (s-n>1)printf("%d\n",s-n);
    if ((s)%n!=1)printf("%d\n",s-1);
    if ((s)%n!=0)printf("%d\n",s+1);
    if (s+n<n*n)printf("%d\n",s+n);
    return 0;
}
