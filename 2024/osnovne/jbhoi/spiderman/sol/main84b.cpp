#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dajemo prednost vecoj zgradi
// a ako su zgrade iste visine, prvo ide ranija jer ona zaklanja drugu
bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> h(n);
    vector<pair<int,int>> vp;
    for(int i=0; i<n; i++) {
        cin >> h[i];
        vp.emplace_back(h[i], i);
    }
    sort(vp.begin(), vp.end(), cmp);
    int curr = -1;
    int skok = 0;
    for(int i=0; i<vp.size(); i++) {
        if(vp[i].second > curr) {
            curr = vp[i].second;
            skok++;
        }
    }
    cout << skok << endl;
}