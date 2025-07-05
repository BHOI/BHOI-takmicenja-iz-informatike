#include <cstdio>

using namespace std;


unsigned long long a,x,m;

unsigned long long step (unsigned long long p)
{
         unsigned long long pp;
         if (p==1)return a;
         if (p==0)return 1;
         if ((p%2)==0){pp=step(p/2)%m;return (pp*pp)%m;}
         else {pp=step(p/2);return (((pp*pp)%m)*a)%m;}
}

int main()
{
    scanf("%llu %llu %llu",&a,&x,&m);
    printf("%llu",step(x));
    return 0;
}
