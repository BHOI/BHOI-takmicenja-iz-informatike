#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int> > ve;
vector<int> tmp;

int MaxUcinak(int n, int k, int p, int s, int* pn)
{
    ve.resize(n);
    tmp.resize(k/2);
    for(int i=0; i<n; i++)
    {
        for(int yes=0; yes<2; yes++)
        {
            for(int j=0; j<k/2; j++)
            {
                tmp[j]=pn[k*i+j]+pn[k*i+k-j-1];
                if(pn[k*i+k-j-1]==s && yes)tmp[j]+=s;
                if(pn[k*i+j]==s && yes)tmp[j]+=s;
            }
            int maxio=tmp[0],trens=tmp[0];
            for(int j=1; j<k/2; j++)
            {
                if(trens<0)trens=0;
                trens+=tmp[j];
                maxio=max(trens,maxio);
            }
            if(yes)ve[i].second=maxio;
            else ve[i].first=maxio;
        }
    }
    sort(ve.rbegin(),ve.rend());
    int maxio=0,rez;
    for(int i=0; i<p; i++)maxio+=ve[i].first;
    for(int i=0; i<n; i++)
    {
        rez=ve[i].second;
        for(int j=0; j<p-!(i<p); j++)
            if(j!=i)rez+=ve[j].first;
        maxio=max(rez,maxio);
    }
    return maxio;
}
