#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX=10005;
int ct = 0;

int we (const string &s) {
	int num[MAX];
	memset(num,0,sizeof num);
	
	char niz[]={'A','C','G','T'};
	
	int res=0;
	for(int i=0;i<4;i++) {
		int n=0;
		for (int j=s.size()-1;j>=0;j--) {
			if(s[j]==niz[i]) { n++; res+=num[j]; }
			num[j]+=n;
		}
	}
	return res;
}

struct cx {
	int w, p; 
	
	bool operator< (const cx & c) const {
		if(w==c.w)return p<c.p;
		return w<c.w;
	}
	
	cx(){}
	cx (const string &_s) {
		w=we(_s);
		p=ct++;
	}
};

string ema[105];
int ec=0;
cx c[105];

int main (void) {
	freopen("dnk.in", "r", stdin);
	freopen("dnk.out", "w", stdout);
	int n; cin>>n;
	string s;
	while(n--) {
		cin>>ema[ec];
		c[ec]=cx(ema[ec]);
		ec++;
	}
	sort(c,c+ec);
	for(int i=0;i<ec;i++)cout<<ema[c[i].p]<<" "<<c[i].w<<endl;
	return 0;
}
