#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    /*
    Mozemo testirati svaki moguci podniz, pocevsi od svakog elementa niza i.
    Testiramo do (n - 1)-og elementa, zato sto nece biti podnizova (duzih od 1),
    pocevsi u njemu, jer ne postoje elementi poslije njega.
    */
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        int len = 1;
        int sign = (l[i] < l[i + 1]);
        for (int j = i; j < n - 1; j++) {
            if (sign and l[j] < l[j + 1]) {
                len++;
            }
            else if (!sign and l[j] > l[j + 1]) {
                len++;
            }
            else {
                break;
            }

            sign = !sign;
        }
        ans = max(ans, len);
    }

    cout << ans << endl;
    return 0;
}
