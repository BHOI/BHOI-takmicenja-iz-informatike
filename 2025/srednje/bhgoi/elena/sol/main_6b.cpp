#include <iostream>
#include <vector>

using namespace std;

int main(){
    int R, K, N;
    bool moze_desno = true, moze_lijevo = true;

    cin >> R >> K >> N;

    string s;
    cin >> s;
    cin >> s;
    if(s[0] == '.'){
        moze_lijevo = false;
    }
    if(s[2] == '.'){
        moze_desno = false;
    }
    cin >> s;
    cin >> s;

    int l=0, r=K-1, c;
    bool c_found = false;
    for(int i=0;i<K;i++){
        if(s[i] == '#') {
            if(!c_found){
                l = i+1;
            }
            else {
                r = i-1;
                break;
            }
        }
        if(s[i] == 'C'){
            c = i;
            c_found = true;
        }
    }

    if(!moze_desno) {
        cout << 1 << ' ' << c + 1 << endl;
        cout << 1 << endl;
        return 0;
    }

    if(!moze_lijevo) {
        cout << 1 << ' ' << max(l + 2, c - N + 1) << endl;
        cout << 1 << endl;
        return 0;
    }

    l++;
    c++;
    r++;

    if(N == 0) {
        cout << 1 << ' ' << c << endl;
        cout << 1 << endl;
        return 0;
    }

    if(N == 1) {
        cout << 1 << ' ' << max(c-1, l) << endl;
        cout << 1 << endl;
        return 0;
    }

    if(N == 2) {
        int br = 1;
        if(c - l > 0) br++;
        if(r - c > 0) br++;
        cout << 1 << ' ' << c << endl;
        cout << br << endl;
        return 0;
    }

    // N == 3

    int br = 1;
    if(c - l >= 2 && r - c >= 1) {
        // #..C.#
        cout << 1 << ' ' << c-1 << endl;
        cout << 4 << endl;
        return 0;
    }
    if(c - l >= 2 && r - c == 0) {
        // #..C#
        cout << 1 << ' ' << c-1 << endl;
        cout << 3 << endl;
        return 0;
    }
    if(c - l == 1 && r - c >= 2) {
        // #.C..#
        cout << 1 << ' ' << c+1 << endl;
        cout << 4 << endl;
        return 0;
    }
    if(c - l == 1 && r - c == 1) {
        // #.C.#
        cout << 1 << ' ' << c-1 << endl;
        cout << 3 << endl;
        return 0;
    }
    if(c - l == 1 && r - c == 0) {
        // #.C#
        cout << 1 << ' ' << c-1 << endl;
        cout << 2 << endl;
        return 0;
    }
    if(c - l == 0 && r - c >= 2) {
        // #C..#
        cout << 1 << ' ' << c+1 << endl;
        cout << 3 << endl;
        return 0;
    }
    if(c - l == 0 && r - c == 1) {
        // #C.#
        cout << 1 << ' ' << c << endl;
        cout << 2 << endl;
        return 0;
    }

    // #C#
    cout << 1 << ' ' << c << endl;
    cout << 1 << endl;
    return 0;
}