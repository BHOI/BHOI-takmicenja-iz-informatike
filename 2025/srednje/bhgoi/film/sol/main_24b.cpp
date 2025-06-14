#include <iostream>

using namespace std;

int main(){
    int n;
    string naslov1, naslov2, naslov3;
    double ocjena1, ocjena2, ocjena3;
    
    cin >> n >> naslov1 >> ocjena1 >> naslov2 >> ocjena2 >> naslov3 >> ocjena3;

    if(ocjena1 > ocjena2 && ocjena1 > ocjena3){
        cout << naslov1;
    } else if(ocjena2 > ocjena1 && ocjena2 > ocjena3){
        cout << naslov2;
    } else {
        cout << naslov3;
    }

    return 0;
}