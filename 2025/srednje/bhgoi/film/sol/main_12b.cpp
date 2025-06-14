#include <iostream>

using namespace std;

int main(){
    int n;
    string naslov;
    float ocjena;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> naslov >> ocjena;
        if(ocjena == 10){
            cout << naslov;
            return 0;
        }
    }
}