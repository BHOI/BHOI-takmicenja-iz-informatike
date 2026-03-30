#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll get_sol(vector<string> arr) {
    vector<char> charset;
    for (char a = 'a'; a <= 'z'; a++)
        charset.push_back(a);
    for (char a = '0'; a <= '9'; a++)
        charset.push_back(a);

    int n = arr.size();
    ll out = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < 4; k++)
                if (arr[i][k] != arr[j][k])
                    cnt++;
            if (cnt == 1)
                out++;
        }
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << get_sol(arr) << "\n";
}