#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct aaa
{
    string y;
    int jac;
    aaa(string _a="",int _vr=0){y=_a;jac=_vr;}
    bool operator < (const aaa &o)const{return jac<o.jac;}
};


vector<aaa>k;
string a;
int ide[100];
int h[5],dos[5],vr=0,n;

int main()
{
    scanf("%d",&n);
    ide['A']=0;ide['C']=1;ide['G']=2;ide['T']=3;
    for (int j=0;j<n;j++)
    {
        cin>>a;

        memset(h,0,sizeof h);
        memset(dos,0,sizeof dos);
        int u=a.length();vr=0;
        for (int i=0;i<u;i++)
        {
            h[ide[a[i]]]++;
        }

        for (int i=0;i<u;i++)
        {
            int ooo=ide[a[i]];
            dos[ooo]++;
            while (ooo--)
            {
                vr+=h[ooo]-dos[ooo];
            }
        }
        k.push_back(aaa(a,vr));
    }
    stable_sort(k.begin(),k.end());
    for (int j=0;j<k.size();j++)cout<<k[j].y<<" "<<k[j].jac<<endl;
    return 0;
}
