#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if(s == "D" || s == "d" || s == "R" || s == "r") {
        cout << "DESNO" << endl;
    } else {
        cout << "LIJEVO" << endl;
    }

    return 0;
}