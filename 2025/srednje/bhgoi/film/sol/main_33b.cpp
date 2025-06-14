#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int n, cijeli_dio, decimalni_dio;
    char tacka;
    cin >> n;

    vector<pair<string, int>> filmovi(n);

    for(int i = 0; i < n; i++){
        cin >> filmovi[i].first >> cijeli_dio >> tacka >> decimalni_dio;
        filmovi[i].second = cijeli_dio * 100 + decimalni_dio;
    }

    int najbolja_ocjena = 0;
    string naslov_najboljeg;
    for(int i = 0; i < n; i++){
        if(filmovi[i].second > najbolja_ocjena){
            najbolja_ocjena = filmovi[i].second;
            naslov_najboljeg = filmovi[i].first;
        }
    }

    cout << naslov_najboljeg << endl;

    return 0;
}