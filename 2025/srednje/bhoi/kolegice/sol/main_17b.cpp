#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int n, m, a, b, iznos;
    cin >> n >> m;

    vector<int> dug(n);
    int ukupan_dug = 0;

    for(int i=0;i<m;i++){
        cin >> a >> b >> iznos;
        dug[a] += iznos;
        ukupan_dug += iznos;
    }

    for(int d = 1000; d >= 0; d--){
        for(int i = 1; i < n; i++){
            if(dug[i] == d){
                cout << i << " " << dug[i] << endl;
            }
        }
    }

    cout << 0 << " " << -ukupan_dug << endl;

    return 0;
}