#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
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

class Rjesenje
{
    bool legal;
    int n,brq;
    vector<int> un;
    vector<int> vel;
#ifdef DFS
    vector<vector<int> > ve;
    int dfs(int x,int p);
#endif // DFS
    int findx(int x);
    void spoji(int x,int y);
public:
    Rjesenje():legal(0),n(-1),brq(0){}
    inline bool spojeni(int x,int y);
    void pravi(int n);
    int koliko(int a,int b);
    friend void napravi_pravo_legalnim_ovo(Rjesenje &x);
};

inline void napravi_pravo_legalnim_ovo(Rjesenje &x)
{
    x.legal=1;
}

int Rjesenje::findx(int x)
{
    if(x>n)throw "Nije dobar parametar u findx";
    if(un[x]!=x)return un[x]=findx(un[x]);
    else return x;
}

void Rjesenje::spoji(int x,int y)
{
    if(spojeni(x,y))throw "Vec su spojeni";
    if(x>y)std::swap(x,y);
    vel[findx(x)]+=vel[findx(y)];
    vel[findx(y)]=-1;
    un[findx(y)]=un[findx(x)];
}

bool Rjesenje::spojeni(int x,int y)
{
    return findx(y)==findx(x);
}

void Rjesenje::pravi(int n)
{
    if(n<1)throw "Nije dobar parametar u pravi";
    this->n=n;
    un.resize(n);
    vel.assign(n,1);
    for(int i=0;i<n;i++)un[i]=i;
#ifdef DFS
    ve.clear();
    ve.resize(n);
#endif // DFS
    brq=0;
}

int Rjesenje::koliko(int a,int b)
{
    if(!legal)throw "Ne Ne, ilegalan pristup klasi";
    a--;b--;
    if(spojeni(a,b))throw "Vec spojeni";
#ifdef DFS
    if(vel[findx(a)]!=dfs(a,-1) ||
       vel[findx(b)]!=dfs(b,-1))
       {
           printf("%d %d %d\n",n,vel[findx(a)],dfs(a,-1));
           printf("%d %d %d\n",n,vel[findx(b)],dfs(b,-1));
           printf("%d %d\n",a,b);cout<<endl;
           throw "DFS nas je izradio";
       }

#endif // DFS
    int rez(abs(vel[findx(a)]-vel[findx(b)])+1);
    spoji(a,b);
#ifdef DFS
    ve[a].pb(b);
    ve[b].pb(a);
#endif // DFS
    return rez;
}

#ifdef DFS
int Rjesenje::dfs(int x,int p)
{
    int rez=1;
    for(int i=0;i<ve[x].size();i++)
    {
        if(ve[x][i]!=p)
            rez+=dfs(ve[x][i],x);
    }
    return rez;
}
#endif // DFS

Rjesenje jeste;

void pravi(int n)
{
    jeste.pravi(n);
    napravi_pravo_legalnim_ovo(jeste);
}

int koliko(int a,int b)
{
    return jeste.koliko(a,b);
}
