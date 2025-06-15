#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int n, m, a, b, iznos;
    cin >> n >> m;

    vector<pair<int, int>> stanje(n);

    for(int i=0;i<n;i++) stanje[i].second = i;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> iznos;
        stanje[a].first -= iznos;
        stanje[b].first += iznos;
    }

    sort(stanje.begin(), stanje.end());

    for(int i = 0; i < n; i++){
        cout << stanje[i].second << " " << -stanje[i].first << endl;
    }

    return 0;
}