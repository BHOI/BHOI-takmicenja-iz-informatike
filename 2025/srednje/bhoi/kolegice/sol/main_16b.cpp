#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int n, m, a, b, iznos, stanje[2]={0, 0};
    cin >> n >> m;
    for(int i=0; i < m; i++){
        cin >> a >> b >> iznos;
        if(a) {
            stanje[0] -= iznos;
            stanje[1] += iznos;
        }
        else {
            stanje[0] += iznos;
            stanje[1] -= iznos;
        }
    }

    if(stanje[0] < 0) {
        cout << 1 << " " << stanje[1] << endl;
        cout << 0 << " " << stanje[0] << endl;
    } else {
        cout << 0 << " " << stanje[0] << endl;
        cout << 1 << " " << stanje[1] << endl;
    }

    return 0;
}