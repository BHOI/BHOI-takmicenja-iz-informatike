#include <cstdio>

using namespace std;

int i,f,e,d,j;

int main()
{
    scanf("%d %d %d %d",&f,&e,&i,&d);
    j=0;
    while (true)
    {
          if ((j*33+i-e)%28==0 && (j*33+i-f)%23==0 && (j*33+i)>d)break;
          j++;
    }
    printf("%d\n",-d+(j*33+i));
    return 0;
}
