#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main () {
    
    int v[8],s,i,m=0,r;
    for (i=0;i<8;i++) cin>>v[i];
    cin>>s;
    s%=360;
    cout<<v[s/45]<<endl;
    for (i=1;i<8;i++) if (v[i]>v[m]) m=i;
    m*=45;
    if (s/45<m/45){
        r=min((m+1)-s, 360-(m+44)+s);
    }
    else if (s/45>m/45){
        r=min(s-(m+44), 360-s+(m+1));
    }
    else r=0;
    cout<<r<<endl;
    return 0;
}
