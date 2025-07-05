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
char c;
int getbau()
{
    c=getchar();
    if(c=='0'||c=='1')return
    ((c-'0')<<4)+((getchar()-'0')<<3)+((getchar()-'0')<<2)+((getchar()-'0')<<1)+((getchar()-'0')<<0);
    return -1;
}
char s[2][50];
int a;
int main()
{
    scanf(" ");
	gets(s[0]);
	scanf(" ");
	gets(s[1]);
	scanf(" ");
	int mod=0;
	while(c!=EOF)
    {
        while((a=getbau())!=-1)
        {
            if(a==32-5){mod=0;continue;}
            if(a==32-1){mod=1;continue;}
            putchar(s[mod][a]);
        }
        putchar('\n');
    }
    puts("");
    return 0;
}
