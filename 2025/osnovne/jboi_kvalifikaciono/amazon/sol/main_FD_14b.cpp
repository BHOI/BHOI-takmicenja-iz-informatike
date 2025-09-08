#include <bits/stdc++.h> 
  
#define ll long long 
  
using namespace std; 
  
const int MAX_N = 200005; 
  
void solve() { 
    int a,b,A=0,B=0; 
    cin >> a >> b; 
    a--; b--; 
    string s; cin >> s; 
    int depth=0; 
    for(int i=0; i<s.length(); i++) { 
        if(s[i] == 'U') depth++; 
        else depth--; 
        if(i == a) A = depth; 
        if(i == b) B = depth; 
    } 
    cout << abs(A-B) << endl; 
} 
  
int main() { 
    int t=1; 
    while(t--) 
        solve(); 
} 