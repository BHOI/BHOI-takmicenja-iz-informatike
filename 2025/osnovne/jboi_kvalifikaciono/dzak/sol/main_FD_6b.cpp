#include <bits/stdc++.h> 
  
#define ll long long 
  
using namespace std; 
  
const int MAX_N = 200005; 
  
void solve() { 
    int n,q; 
    cin >> n >> q; 
    int t[n]; 
    for(int i=0; i<n; i++) cin >> t[i]; 
    map<int,int>m[31]; 
    map<int,int>stepeni; 
    for(int i=0; i<=30; i++) { 
        ll stepen = (1 << i); 
        stepeni[stepen] = i; 
        for(int j=0; j<n; j++) { 
            m[i][t[j]%stepen]++; 
        } 
    } 
    while(q--) { 
        int v,p; cin >> v >> p; 
        cout << m[stepeni[v]][p] << endl; 
    } 
} 
  
int main() { 
    int t=1; 
    while(t--) 
        solve(); 
} 