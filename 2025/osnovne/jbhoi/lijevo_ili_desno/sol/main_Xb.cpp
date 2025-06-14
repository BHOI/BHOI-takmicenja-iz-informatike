#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if(s[0] == 'd' || s[0] == 'r') {
        cout << "DESNO" << endl;
    } else {
        cout << "LIJEVO" << endl;
    }

    return 0;
}