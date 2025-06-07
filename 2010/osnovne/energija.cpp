#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct el {
	int p, c;
};

bool sortf(el a, el b) { return a.c<b.c; }

int main (void) 
{
	freopen("energija.in","r",stdin);
	freopen("energija.out","w",stdout);

	int n, w; cin>>n>>w;
	
	el e[1005];
	for (int i=0;i<n;i++)
		cin>>e[i].p>>e[i].c;
	sort (e,e+n,sortf);
	
	int c=0;
	for(int i=0;i<n;i++)
	{
		int n=min(w,e[i].p);
		w-=n;
		c+=n*e[i].c;
	}
	
	cout<<c<<endl;
	
	return 0;
}
