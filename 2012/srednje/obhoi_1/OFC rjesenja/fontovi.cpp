/// 786

#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstring> 
using namespace std;

const int maxp = 26;
int mali[maxp], veliki[maxp];
char recenica[10005];

int main (void) {
	freopen("fontovi.in","r",stdin);
	freopen("fontovi.out","w",stdout);

	gets(recenica);
	scanf("\n");
	for(int i=0;i<26;i++)scanf("%d",&veliki[i]);
	for(int i=0;i<26;i++)scanf("%d",&mali[i]);
	int l=strlen(recenica);
	int r=0;
	for(int i=0;i<l;i++){
		if(recenica[i]>='a'&&recenica[i]<='z')
			r+=mali[recenica[i]-'a'];
		if(recenica[i]>='A'&&recenica[i]<='Z')
			r+=veliki[recenica[i]-'A'];
		if(recenica[i]==' ')
			r+=3;
		if(i) ++r;
	}
	printf("%d\n",r);

	return 0;
}
