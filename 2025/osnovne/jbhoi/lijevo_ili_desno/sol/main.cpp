#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if(s[0] == 'd' || s[0] == 'D' || s[0] == 'r' || s[0] == 'R') {
        cout << "DESNO" << endl;
    } else {
        cout << "LIJEVO" << endl;
    }

    return 0;
}