#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> karte;

bool moze_asimetrija(int x){

    int dekMax = 0, dekMin = 1e9, dekovi = 1;
    for(size_t i = 0; i < n; i++){
        dekMax = max(karte[i], dekMax);
        dekMin = min(karte[i], dekMin);
        if((dekMax - dekMin) > x){
            if(++dekovi > k) return false;
            dekMax = dekMin = karte[i];
        }
    }
    return true;
}

int main() {

    cin >> n >> k;
    karte.resize(n);

    int maxSnaga = 0;
    for(size_t i = 0; i < n; i++){
        cin >> karte[i];
        maxSnaga = max(karte[i], maxSnaga);
    }

    int lo = 0, hi = maxSnaga, mid, asimetrija = 1e9;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(moze_asimetrija(mid)) {
            asimetrija = min(mid, asimetrija);
            hi = mid - 1;
        } else{
            lo = mid + 1;
        }
    }

    cout << asimetrija << endl;


    return 0;
}