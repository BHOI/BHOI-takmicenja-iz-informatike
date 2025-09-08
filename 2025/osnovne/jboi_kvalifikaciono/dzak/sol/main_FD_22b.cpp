#include <bits/stdc++.h> 
  
#define ll long long 
  
using namespace std; 
  
const int MAX_N = 200005; 
  
void solve() { 
    int n,q; 
    cin >> n >> q; 
    int t[n]; 
    for(int i=0; i<n; i++) cin >> t[i]; 
    int ostaci[16]; 
    memset(ostaci,0,sizeof ostaci); 
    for(int i=0; i<n; i++) ostaci[t[i]%16]++; 
    while(q--) { 
        int v,p; 
        cin >> v >> p; 
        p %= v; 
        cout << ostaci[p] << " "; 
    } 
    cout << endl; 
} 
  
int main() { 
    int t=1; 
    while(t--) 
        solve(); 
} 