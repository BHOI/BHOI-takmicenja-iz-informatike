/// 786

#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

bool ok (const string &s) {
	int open=0;
	for(int i=0;i<s.size();i++) {
		if(s[i]=='[')++open;
		if(s[i]==']')--open;
		if(open<0)return false;
	}
	return (open==0);
}

int main (void)
{
	string s;
	for(int i=0;i<3;i++){
		cin>>s;
		cout<<(ok(s)?":)":":(")<<endl;
	}
	return 0;
}
