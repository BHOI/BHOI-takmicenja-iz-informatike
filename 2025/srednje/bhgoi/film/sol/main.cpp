#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    string naslov, naslov_najboljeg;
    double ocjena, najbolja_ocjena = 0;

    for(int i = 0; i < n; i++){
        cin >> naslov >> ocjena;
        if(ocjena > najbolja_ocjena){
            najbolja_ocjena = ocjena;
            naslov_najboljeg = naslov;
        }
    }
    cout << naslov_najboljeg << endl;

    return 0;
}