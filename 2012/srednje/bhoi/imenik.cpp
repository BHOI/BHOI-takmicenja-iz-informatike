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
const int Poc=100000;
struct node
{
    int t[11];
    vector<int> prlz;
    node(){memset(t,-1,sizeof t);prlz.clear();}
};
struct trie
{
    vector<node> x;
    vector<int> tmp;
    int root,T;
    trie(){x.resize(Poc);root=0;T=0;}
    int add(int tr,char vl,int inx)
    {
//        if(!x[tr].prlz.size())x[tr].prlz.pb(inx);
//        if(x[tr].prlz.back()!=inx)x[tr].prlz.pb(inx);
        if(x[tr].t[vl]!=-1)return x[tr].t[vl];
        else
        {
            if(T+50>x.size())x.resize(x.size()+500);
            return x[tr].t[vl]=++T;
        }
    }
    void dfs(int tr)
    {
        for(int i=0;i<10;i++)
        {
            if(x[tr].t[i]!=-1)
                dfs(x[tr].t[i]);
        }
        for(int i=0;i<x[tr].prlz.size();i++)tmp.pb(x[tr].prlz[i]);
    }
    void prtz(string a,vector<int> &z)
    {
        int I=0,tr=root;
        //printf("%d\n",x.size());

        while(I<a.size() && tr!=-1)
        {
            //printf("%d\n",tr);
            tr=x[tr].t[a[I++]-'0'];
        }
        if(tr!=-1)
        {
            tmp.clear();
            dfs(tr);
            sort(tmp.begin(),tmp.end());
            tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
            z=tmp;
        }
        else z=vector<int>();
    }
}drv;
int ubr(char p)
{
    p=tolower(p);
    if(isdigit(p))return p-'0';
    if('a'<=p && p<='c')return 2;
    if('d'<=p && p<='f')return 3;
    if('g'<=p && p<='i')return 4;
    if('j'<=p && p<='l')return 5;
    if('m'<=p && p<='o')return 6;
    if('p'<=p && p<='s')return 7;
    if('t'<=p && p<='v')return 8;
    if('w'<=p && p<='z')return 9;
    return 1;
}
struct ime
{
    char komp[60];
    ime(){}
    ime(string &a,int inx)
    {
		while(a[a.size()-1]==' ')a.resize(a.size()-1);
		memset(komp,0,sizeof komp);
        for(int i=0;a[i];i++)komp[i]=a[i];
        a+=' ';
        int I=12,tr;
        while(I<a.size())
        {
            tr=drv.root;
			int inii=I;
            while(a[I]!=' ')
            {
                if(I-inii<11)
                    tr=drv.add(tr,ubr(a[I]),inx);
                //komp[I]=ubr(a[I])+'0';
                I++;
            }
            if(!drv.x[tr].prlz.size())drv.x[tr].prlz.pb(inx);
            if(drv.x[tr].prlz.back()!=inx)drv.x[tr].prlz.pb(inx);
            drv.add(tr,1,inx);
            I++;
        }
    }
//    void isp(){puts(komp.c_str());}
};
bool cmp(const string &x,const string &y)
{
    for(int i=12;i<min(x.size(),y.size());i++)
    {
        if(x[i]!=y[i])return x[i]<y[i];
    }
    return x.size()<=y.size();
}
char s[500];
vector<ime> svi;
vector<string> tmp;
vector<int> z;
int n,q;
int main()
{
    //freopen("imenik8.in","r",stdin);
    //freopen("out.txt","w",stdout);
    drv=trie();
	scanf("%d %d",&n,&q);
	svi.resize(n);tmp.resize(n);
	for(int i=0;i<n;i++)
	{
	    scanf(" ");gets(s);
	    tmp[i]=s;
	}
	stable_sort(tmp.begin(),tmp.end(),&cmp);
	for(int i=0;i<n;i++)svi[i]=ime(tmp[i],i);
	while(q--)
    {
        scanf(" ");gets(s);
        z.clear();
        drv.prtz(s,z);
        printf("%s:\n",s);
        for(int i=0;i<z.size();i++)
        {
            puts(svi[z[i]].komp);
            //cout<<svi[z[i]].komp<<endl;
            //puts("A");
        }
    }
    return 0;
}
