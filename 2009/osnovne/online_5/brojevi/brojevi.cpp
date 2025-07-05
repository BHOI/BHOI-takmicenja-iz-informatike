/// 786

#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main (void)
{
	int n;cin>>n;
	
	int zbir=0,proizvod=1,sljedeci=n+1;
	do zbir+=n%10,proizvod*=n%10; while(n/=10);
	for(;sljedeci%zbir;++sljedeci);
	
	cout<<zbir<<endl<<proizvod<<endl<<sljedeci<<endl;
	return 0;
}
