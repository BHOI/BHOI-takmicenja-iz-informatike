#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
int main () {
    freopen("podniz.in", "r", stdin);
    freopen("podniz.out", "w", stdout);
    string str;
    int niz[1000]={0},i,duzina=0;
    cin>>str;
    for (i=2;i<str.size();i++){
        if (abs(str[i]-str[i-1])==abs(str[i-1]-str[i-2]) && abs(str[i]-str[i-1])!=0) niz[i]=niz[i-1]+1;
        duzina=max(niz[i], duzina);
    }
    if (duzina!=0) duzina+=2;
    cout<<duzina;
    return 0;
}
