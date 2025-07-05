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
typedef long long lint;
int n,k;
vector<int> a;
bool moze(lint x)
{
    lint trs=0;
    int f=0;
    for(int i=n-1;i>=0;i--)
    {
        if(trs+a[i]>x){trs=a[i];f++;}
        else trs+=(lint)a[i];
    }
    return f<k;
}
vector<int> f;
void isp(lint x)
{
    lint trs=0;
    f.reserve(k+1);
    for(int i=n-1;i>=0;i--)
    {
        if(trs+a[i]>x){trs=a[i];f.pb(i);}
        else trs+=(lint)a[i];
    }
    int I=0;
    reverse(f.begin(),f.end());
    int ubc=-1,dos=f.size();
    for(int i=0;i<k-dos-1;i++){while(binary_search(f.begin(),f.begin()+dos,++ubc));f.pb(ubc);}
    sort(f.begin(),f.end());
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(I<f.size() && f[I]==i){putchar(' ');putchar('/');putchar(' ');I++;}
        else if(i!=n-1)putchar(' ');
    }
   // printf(" %d %d\n",f.size(),k);
    puts("");
}
char c;
inline void fast_input(int &x)
{
    while((c=getchar())<'0');
    x=c-'0';
    while((c=getchar())>='0')x=x*10+c-'0';
}
int main()
{
    //freopen("kopiranje10.in","r",stdin);
	scanf("%d %d",&n,&k);a.resize(n);
	lint low=1<<29,high=0,mid=0;
	for(int i=0;i<n;i++)
    {
        //scanf("%d",&a[i]);
        a[i]=0;
        fast_input(a[i]);
        high+=(lint)a[i];
        low=min(low,(lint)a[i]-1);
    }
    low=max(high/k+1,low);
    while(low<high)
    {
        if(low==high-1){if(moze(low))high=low;else low=high;break;}
        mid=(low+high)/2;
        if(moze(mid))high=mid;
        else low=mid;
    }
    //printf("%d\n",low);
    isp(low);
    return 0;

}
