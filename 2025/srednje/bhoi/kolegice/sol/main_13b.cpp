#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int n, m, a, b, iznos;
    cin >> n >> m;

    cin >> a >> b >> iznos;
    
    cout << a << " " << iznos << '\n';
    for(int i=0;i<n;i++) {
        if(i != a && i != b) {
            cout << i << " 0\n";
        }
    }
    cout << b << " " << -iznos << '\n';

    return 0;
}