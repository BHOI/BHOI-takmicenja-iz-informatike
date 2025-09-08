#include <bits/stdc++.h> 
  
#define ll long long 
  
using namespace std; 
  
const int MAX_N = 200005; 
  
void solve() { 
    int a,b; 
    cin >> a >> b; 
    int cnt=0; 
    string s; cin >> s; 
    if(a > b) swap(a,b); 
    for(int i=a; i<min(b,(int)s.length()); i++) { 
        //cout << s[i]; 
        if(s[i] == 'D' and cnt) cnt--; 
        else cnt++; 
    } 
    //cout << endl; 
    cout << cnt << endl; 
} 
  
int main() { 
    int t=1; 
    while(t--) 
        solve(); 
} 