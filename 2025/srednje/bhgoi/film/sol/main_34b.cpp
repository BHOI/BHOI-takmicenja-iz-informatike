#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<string, double>> filmovi(n);

    for(int i = 0; i < n; i++){
        cin >> filmovi[i].first >> filmovi[i].second;
    }

    while(true) {
        next_permutation(filmovi.begin(), filmovi.end());

        bool poredani = true;
        for(int i = 1; i < n; i++){
            if(filmovi[i].second > filmovi[i-1].second){
                poredani = false;
                break;
            }
        }
        
        if(poredani) {
            cout << filmovi[0].first << endl;
            break;
        }
    }

    return 0;
}