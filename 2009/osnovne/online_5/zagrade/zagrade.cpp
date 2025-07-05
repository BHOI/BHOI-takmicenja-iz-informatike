/// 786

#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main (void)
{
	string s;
	cin>>s;
	for (int i=0;i<5;i++){
		for (int j=0;j<s.size();j++) {
			if(i==0||i==4) {
				if (s[j]=='('&&i==0)cout<<" /-";
				if (s[j]=='('&&i==4)cout<<" \\-";
				if (s[j]==')'&&i==0)cout<<"-\\ ";
				if (s[j]==')'&&i==4)cout<<"-/ ";
				if (s[j]=='['||s[j]=='{')cout<<" --";
				if (s[j]==']'||s[j]=='}')cout<<"-- ";
			}
			else {
				if(s[j]=='('||s[j]=='[') cout<<"|  ";
				if(s[j]==')'||s[j]==']') cout<<"  |";
				if(s[j]=='{')cout<<(i==2?"<  ":"|  ");
				if(s[j]=='}')cout<<(i==2?"  >":"  |");
			}
			cout << " ";
		}
		cout<<endl;  
	}
	return 0;
}
