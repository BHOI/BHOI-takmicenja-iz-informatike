#include <bits/stdc++.h>
using namespace std;

string getLow(string s){
    sort(s.begin(), s.end());
    return s;
}

string getHigh(string s){
    sort(s.begin(), s.end(), greater <char>());
    return s;
}

int main(){
    int n;
    cin >> n;
    vector <string> baza(n), lowOrder(n), highOrder(n);

    for(int i = 0; i < n; ++i){
        cin >> baza[i];
        lowOrder[i] = getLow(baza[i]);
        highOrder[i] = getHigh(baza[i]);
    }

    sort(lowOrder.begin(), lowOrder.end());
    sort(highOrder.begin(), highOrder.end());

    for(int i = 0; i < n; ++i){
        int lowerBound = lower_bound(highOrder.begin(), highOrder.end(), getLow(baza[i])) - highOrder.begin() + 1;
        int upperBound = upper_bound(lowOrder.begin(), lowOrder.end(), getHigh(baza[i])) - lowOrder.begin();
        cout << lowerBound << " " << upperBound << "\n";
    }

    return 0;
}
