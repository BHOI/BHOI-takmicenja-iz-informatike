#include <bits/stdc++.h> 
  
#define ll long long 
  
using namespace std; 
  
const int MAX_N = 200005; 
  
void solve() { 
    int n,q; 
    cin >> n >> q; 
    int t[n]; 
    for(int i=0; i<n; i++) cin >> t[i]; 
    while(q--) { 
        int v,p; 
        cin >> v >> p; 
        p %= v; 
        int ans=0; 
        for(int i=0; i<n; i++) { 
            if(t[i] % v == p) ans++; 
        } 
        cout << ans << " "; 
    } 
    cout << endl; 
} 
  
int main() { 
    int t=1; 
    while(t--) 
        solve(); 
} 