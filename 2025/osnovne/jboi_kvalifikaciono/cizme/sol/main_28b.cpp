#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool poredane(vector<int>& stanje) {
    for(int i = 0; i < stanje.size() - 1; i++) {
        if(stanje[i] == 0 && stanje[i + 1] == 1) return false;
        if(stanje[i] == 2 && stanje[i + 1] == 0) return false;
        if(stanje[i] == 2 && stanje[i + 1] == 1) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector <int> stanje(n), potezi;
    for(int i = 0; i < n; i++) {
        cin >> stanje[i];
    }

    while(!poredane(stanje)) {
        // Potezi po 1 mjesto:
        for(int i = 0; i < stanje.size() - 1; i++) {
            if(stanje[i] == 0 && stanje[i + 1] == 1) {
                swap(stanje[i], stanje[i + 1]);
                potezi.push_back(i + 1);
            }
            else if(stanje[i] == 2 && stanje[i + 1] == 0) {
                swap(stanje[i], stanje[i + 1]);
                potezi.push_back(i);
            }
        }
        
        // Potezi po 2 mjesta:
        for(int i = 1; i < stanje.size() - 1; i++) {
            if(stanje[i] == 0) continue;  // Nije moguce preskociti preko praznog polja
            if(stanje[i - 1] == 2 && stanje[i + 1] == 0) {
                swap(stanje[i - 1], stanje[i + 1]);
                potezi.push_back(i - 1);
            }
            if(stanje[i - 1] == 0 && stanje[i + 1] == 1) {
                swap(stanje[i - 1], stanje[i + 1]);
                potezi.push_back(i + 1);
            }
        }
    }

    cout << potezi.size() << endl;
    for(int i = 0; i < potezi.size(); i++) {
        cout << potezi[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}