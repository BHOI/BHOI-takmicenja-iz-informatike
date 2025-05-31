#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > ve;
vector<int> ispod;
int dfs(int x,int p)
{
  int br=1;
  for(int i=0;i<(int)ve[x].size();i++)
  {
    if(ve[x][i]==p)continue;
    br+=dfs(ve[x][i],x);
  }
  return ispod[x]=br;
}

int main()
{
  int n,a;
  scanf("%d",&n);
  ve.resize(n);
  ispod.resize(n);
  for(int i=0;i<n-1;i++)
  {
    scanf("%d",&a);
    ve[a].push_back(i+1);
  }
  dfs(0,-1);
  for(int i=0;i<n;i++)
    printf("%d%c",ispod[i],(i==n-1)?'\n':' ');
  return 0;
}
