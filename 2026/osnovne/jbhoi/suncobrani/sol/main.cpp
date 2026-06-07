#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Interval {
    ll l, r, val;
    Interval() {}
    Interval(ll l, ll r, ll val) : l(l), r(r), val(val) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, L;
    cin >> n >> L;
    map<ll, ll> events;
    for (int i = 0; i < n; i++) {
        ll a, b, d;
        cin >> a >> b >> d;
        events[a] += d;
        events[b + 1] -= d;
    }

    // Implicitno gradimo difference array
    vector<pii> vazne_tacke;
    ll sum = 0;
    for (auto &[x, y] : events) {
        sum += y;
        vazne_tacke.emplace_back(x, sum);
    }
    // Ako vazne_tacke[i].first <= x < vazne_tacke[i].second onda je debljina na mjestu x, vazne_tacke[i].second

    vector<Interval> vazni_intervali;
    for (int i = 1; i < vazne_tacke.size(); i++)
        vazni_intervali.emplace_back(vazne_tacke[i - 1].first, vazne_tacke[i].first - 1, vazne_tacke[i - 1].second);

    // Sada tvrdimo da će optimalni interval uvijek imati jedan kraj da se poklapa sa krajem vaznog intervala.
    // U suštini ovo je istina zato što, kad malo pomjerimo neki interval koji nema granice na krajevima vaznog intervala,
    // Dobijemo ili interval koji ima lijevu granicu sa manjom koordinatom ili interval sa boljom zaštitom.
    // Ovo se može formalno dokazati tehnikom kontradikcije. Prvo ćemo pretpostaviti da takav interval postoji, pa ćemo dokazati da 
    // taj interval zapravo nije optimalan.
    // Recimo da je optimalni interval [l, r] i l i r nisu krajevi niti jednog intervala
    // Neka je D[x] debljina na poziciji x. To znači da D[l - 1] == D[l] == D[l + 1] i D[r - 1] == D[r] == D[r + 1]

    // Ako D[l] == D[r], onda zaštita intervala [l, r] je
    // D[l] + D[l + 1] + ... + D[r] == D[l] + ... + D[r - 1] + D[l - 1] == D[l - 1] + ... + D[r - 1]
    // što znači da [l, r] ima istu ukupnu zaštitu kao [l - 1, r - 1] tako da [l, r] nije optimalan

    // Ako D[l] < D[r] onda:
    // D[l] + D[l + 1] + ... D[r] < D[r + 1] + D[l + 1] + .. D[r] == D[l + 1] .. D[r + 1]
    // što znači da [l + 1, r + 1] ima veću ukupnu zaštitu od [l, r]  tako da [l, r] nije optimalan

    // Ako D[l] > D[r] onda sličnim argumentom dobijemo da[l - 1, r - 1] ima veću ukupni zaštitu 
    // od [l, r] tako da [l, r] nije optimalan

    // sada ćemo izračunati sumu svakog intervala sa lijevom granicom na svakom intervalu

    ll out_l = 0, out_vr = -1e9;

    ll l = 0, r = 0; // lijeva granica je na vazni_intervali[l].first i desna granica je unutar intervala vazni_intervali[r - 1]
    ll c_sum = 0;
    for (; l < vazni_intervali.size(); l++) {
        ll tren_desna = vazni_intervali[l].l + L - 1;
        while (r < vazni_intervali.size() && !(vazni_intervali[r].l <= tren_desna && vazni_intervali[r].r >= tren_desna))
        {
            c_sum += 1LL * (vazni_intervali[r].r - vazni_intervali[r].l + 1) * vazni_intervali[r].val;
            r++;
        }

        // trebamo dodati presjek sa interval na indeksu r
        ll ukupno = c_sum;
        if (r < vazni_intervali.size())
            ukupno += 1LL * (tren_desna - vazni_intervali[r].l + 1) * vazni_intervali[r].val;

        if (ukupno > out_vr)
            out_l = vazni_intervali[l].l, out_vr = ukupno;

        c_sum -= 1LL * (vazni_intervali[l].r - vazni_intervali[l].l + 1) * vazni_intervali[l].val;
    }

    // sada radimo naopako
    // fiksiramo desnu granicu na kraj vaznog intervala

    ll desni = static_cast<int>(vazni_intervali.size()) - 1;
    ll lijevi = static_cast<int>(vazni_intervali.size()) - 1;

    ll c_sum2 = 0;

    for (; desni >= 0; desni--) {
        ll tren_lijeva = vazni_intervali[desni].r - L + 1;

        while (lijevi >= 0 && !(vazni_intervali[lijevi].l <= tren_lijeva && vazni_intervali[lijevi].r >= tren_lijeva)) {
            c_sum2 += 1LL * (vazni_intervali[lijevi].r - vazni_intervali[lijevi].l + 1) * vazni_intervali[lijevi].val;
            lijevi--;
        }

        // trebamo dodati presjek sa intervalom na indeksu lijevi
        ll ukupno = c_sum2;

        if (lijevi >= 0)
            ukupno += 1LL * (vazni_intervali[lijevi].r - tren_lijeva + 1) * vazni_intervali[lijevi].val;

        if (ukupno > out_vr || (ukupno == out_vr && tren_lijeva < out_l))
            out_vr = ukupno, out_l = tren_lijeva;

        c_sum2 -= 1LL * (vazni_intervali[desni].r - vazni_intervali[desni].l + 1) * vazni_intervali[desni].val;
    }

    cout << out_l << " " << out_l + L - 1 << "\n";
}