#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long lint;
long long n;


long long prrj(lint n)
{
    long long var=1,rez=0;
    for (int i=0; i<64; i++)
    {
        rez+=(long long)(!!((1LL<<i)&n))*var;
        var*=3;
    }
    return rez;
}

inline int valid1(lint n)
{
    lint k=3486784401LL;//3^20;
   // cout<<k;fflush(stdout);
    while (n>=1 && k)
    {
    //    cout<<n<<" "<<k<<endl;
        if (n>=k)n-=k;
        k/=3;
    }
    return !n;
}

long long brute1(lint n)
{
    lint c=0,i;
    for(i=1;c!=n;i++)
    {
       // cout<<i<<endl;
        if (valid1(i))
            c++;
    }
    //printf("%lld\n",i);
    return i-1;
}

long long brute2(lint n,int arg=0)
{
    lint k=34359738368LL,f=35;//2^35
    while (n<k){k/=2;f--;}
    lint s=1LL<<(f+1),rez=0;
    vector<lint> ve;
    set<lint> se;
    se.clear();ve.clear();
    for(lint i=0;i<s;i++)
    {
        rez=0;k=1;
        for(int j=0;j<64;j++)
        {
            rez+=(!!((1LL<<j)&i))*k;
            k*=3;
        }
        if (!arg)ve.push_back(rez);
        else se.insert(-rez);
        if (arg && se.size()>n)return -(*(se.begin()));
    }
  //  cout<<"velicina:"<<ve.size()<<endl;
    sort(ve.begin(),ve.end());
  //  for(int i=0;i<ve.size();i++)printf("%d ",ve[i]);putchar('\n');
    return ve[n];
}

long long rez(lint n)
{
    //return prrj(n); //pravo rjesenje O(log(N));
    //return brute1(n); //O(N^(3/2)*logN);
    //return brute2(n,0); //O(n) sa bitmaskom;    sa vektorom i sort;//prva cetiri prolazi subtaska, vjerovatno
    //return brute2(n,1); //O(n) sa bitmaskom;    sa setom;//prva cetiri prolazi subtaska, vjerovatno
    //return brute3(n); //O(n) sa backtrackingom;
    return n;
}


int main()
{
	int n;
	cin >> n;
	cout << prrj(n) << endl;
    return 0;
}
