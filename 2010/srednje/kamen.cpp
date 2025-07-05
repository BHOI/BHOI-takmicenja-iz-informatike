#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct kamen
{
       vector <int> manji;
       vector <int> veci;
}a[105];

bool vecp[105],manp[105];

void manpd(int l)
{
     int pp=a[l].manji.size();manp[l]=1;
     for (int j=0;j<pp;j++)
     {
         if (!manp[a[l].manji[j]])manpd(a[l].manji[j]);
         for (int o=0;o<a[a[l].manji[j]].manji.size();o++)a[l].manji.push_back(a[a[l].manji[j]].manji[o]);
     }
     
     
     vector <int>::iterator it1,it2;
     sort (a[l].manji.begin(),a[l].manji.end());
     sort (a[l].veci.begin(),a[l].veci.end());
     it1=unique(a[l].manji.begin(),a[l].manji.end());
     a[l].manji.resize( it1 - a[l].manji.begin() );
     it2=unique(a[l].veci.begin(),a[l].veci.end());
     a[l].veci.resize( it2 - a[l].veci.begin() );
     
     return;
}

void vecid(int l)
{
     int pp=a[l].veci.size();vecp[l]=1;
     for (int j=0;j<pp;j++)
     {
         if (!vecp[a[l].veci[j]])vecid(a[l].veci[j]);
         for (int o=0;o<a[a[l].veci[j]].veci.size();o++)a[l].veci.push_back(a[a[l].veci[j]].veci[o]);
     }
     
     vector <int>::iterator it1,it2;
     sort (a[l].manji.begin(),a[l].manji.end());
     sort (a[l].veci.begin(),a[l].veci.end());
     it1=unique(a[l].manji.begin(),a[l].manji.end());
     a[l].manji.resize( it1 - a[l].manji.begin() );
     it2=unique(a[l].veci.begin(),a[l].veci.end());
     a[l].veci.resize( it2 - a[l].veci.begin() );
     
     
     return;
}//6


int main()
{
    int n,m,c=0;
    scanf("%d %d",&n,&m);
    int k=(n-1)/2,y,x;
    for (int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        a[x].manji.push_back(y);
        a[y].veci.push_back(x);
    }
    memset(manp,0,sizeof manp);
    memset (vecp,0,sizeof vecp);
    for (int i=1;i<=n;i++)
    {
        if (!manp[i] && !a[i].manji.empty())manpd(i);
        if (!vecp[i] && !a[i].veci.empty())vecid(i);
        /*vector <int>::iterator it1,it2;
       sort (a[i].manji.begin(),a[i].manji.end());
        sort (a[i].veci.begin(),a[i].veci.end());
        it1=unique(a[i].manji.begin(),a[i].manji.end());
        a[i].manji.resize( it1 - a[i].manji.begin() );
        it2=unique(a[i].veci.begin(),a[i].veci.end());
        a[i].veci.resize( it2 - a[i].veci.begin() );*/
        if (a[i].manji.size()>k || a[i].veci.size()>k)c++;
        
    }
    printf("%d\n",c);
    scanf("%d",&c);
    return 0;
}
