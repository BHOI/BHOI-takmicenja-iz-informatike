#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int R, C, N, Q;
    cin >> R >> C >> N >> Q;

    vector<vector<pair<int, int>>> umbrellas(R + 1);
    for (int i = 0; i < N; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        r--;
        umbrellas[r].push_back({a, b});
    }

    vector<int> drops(C + 1, 1);
    vector<int> temp(C + 1, 0);
    vector<int> dir(C + 1, 1);
    for (int i = 0; i < R; i++) {
        if (umbrellas[i].empty())
            continue;
        iota(all(dir), 0);
        fill(all(temp), 0);
        for (auto [l, r] : umbrellas[i])
            for (int j = 0; j < (r - l + 1) / 2; j++)
                dir[l + j] = l - 1, dir[r - j] = r + 1;
        for (int j = 0; j <= C; j++) 
            temp[dir[j]] += drops[j];
        swap(temp, drops);
    }

    for (int i = 1; i <= C; i++)
        drops[i] += drops[i - 1];
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << drops[b] - drops[a - 1] << "\n";
    }
}