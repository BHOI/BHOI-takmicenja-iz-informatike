#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, N, Q;
    cin >> R >> C >> N >> Q;

    int ua = 0, ub = 0;
    for (int i = 0; i < N; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        ua = a;
        ub = b;
    }

    for (int q = 0; q < Q; q++) {
        int L, D;
        cin >> L >> D;

        if (N == 0) {
            int lo = L, hi = D;
            if (lo < 1) lo = 1;
            if (hi > C) hi = C;
            cout << ((lo <= hi) ? hi - lo + 1 : 0) << "\n";
            continue;
        }

        // Jedan kisobran [ua, ub]
        // Preslikavanje: kolone 1..ua-1 padaju ravno,
        // kolone ua..ua+w/2-1 padaju na ua-1,
        // kolone ua+w/2..ub padaju na ub+1,
        // kolone ub+1..C padaju ravno
        //
        // Ukupno na zemlji:
        // kolona k, k < ua-1: 1 kap (originalna)
        // kolona ua-1: 1 (originalna, ako ua-1 >= 1) + w/2 (sa kisobrana)
        // kolone ua..ub: 0 kapi
        // kolona ub+1: 1 (originalna, ako ub+1 <= C) + w/2 (sa kisobrana)
        // kolona k, k > ub+1: 1 kap (originalna)
        //
        // Specijalni slucaj: ua=1, tada ua-1=0 (van mreze), tih w/2 kapi se gubi
        // Specijalni slucaj: ub=C, tada ub+1=C+1 (van mreze), tih w/2 kapi se gubi

        int w = ub - ua + 1;
        ll count = 0;

        // Ravne kapi: kolone [1, ua-2] i [ub+2, C]
        {
            int lo = (L > 1) ? L : 1;
            int hi = (D < ua - 2) ? D : ua - 2;
            if (lo <= hi) count += hi - lo + 1;
        }
        {
            int lo = (L > ub + 2) ? L : ub + 2;
            int hi = (D < C) ? D : C;
            if (lo <= hi) count += hi - lo + 1;
        }

        // Kolona ua-1
        int left_col = ua - 1;
        if (left_col >= 1 && left_col <= C && left_col >= L && left_col <= D) {
            count += 1 + w / 2;
        }

        // Kolona ub+1
        int right_col = ub + 1;
        if (right_col >= 1 && right_col <= C && right_col >= L && right_col <= D) {
            count += 1 + w / 2;
        }

        cout << count << "\n";
    }

    return 0;
}
