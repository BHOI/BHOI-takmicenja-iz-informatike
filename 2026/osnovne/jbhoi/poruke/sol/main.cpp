#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    string a, b;
    cin >> a >> b;

    if (t == 0) {
        // Provjera da li je A podstring od B
        if (b.find(a) != string::npos) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    } else {
        // Provjera da li je A podniz od B
        int i = 0, j = 0;
        while (i < (int)a.size() && j < (int)b.size()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        if (i == (int)a.size()) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    }
    return 0;
}
