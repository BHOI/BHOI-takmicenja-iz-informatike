#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int cnt[101] = {};
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cnt[c]++;
    }

    for (int i = 1; i <= 100; i++)
        if (cnt[i] >= k) {
            cout << k - 1 << endl;
            return 0;
        }

    cout << n << endl;
    return 0;
}