#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct slide {
    int l, r, dest;

    slide() {}
    slide(int l, int r, int dest) : l(l), r(r), dest(dest) {}
};

pii intersect(pii a, pii b) {
    int l = max(a.first, b.first);
    int r = min(a.second, b.second);

    if (l > r) return {-1, -2}; // no intersection
    return {l, r};
}

inline int size(pii x) {return x.second - x.first + 1;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r, c, n, q;
    cin >> r >> c >> n >> q;

    vector<vector<slide> > slides(r);
    for (int i = 0; i < n; i++) {
        int R, l, r;
        cin >> R >> l >> r;
        
        slides[R - 1].emplace_back(l, (l + r - 1) / 2, l - 1);
        slides[R - 1].emplace_back((r + l + 1) / 2, r, r + 1);
    }

    set<pii> untouched;
    untouched.insert(pii(0, c));
    multiset<pii> drop_clumps; // first is coordinate second is count
    for (int i = 0; i < r; i++) {
        // we first split the untouched
        for (auto &slide : slides[i]) {
            // see if there is an intersection such that l < slide.l
            int num = 0;
            auto first_possible = untouched.lower_bound(pii(slide.l, -1));
            if (first_possible != untouched.begin() && intersect(*prev(first_possible), pii(slide.l, slide.r)) != pii(-1, -2)) {
                first_possible--;
                untouched.insert(pii(first_possible->first, slide.l - 1));
                num += min(first_possible->second, slide.r) - slide.l + 1;

                if (first_possible->second > slide.r)
                    untouched.insert(pii(slide.r + 1, first_possible->second));
                untouched.erase(first_possible);
            }

            // now check out the untouched which have l >= slide.l
            while (untouched.size()) {
                auto first_possible = untouched.lower_bound(pii(slide.l, -1));
                if (first_possible == untouched.end() || first_possible->first > slide.r)
                    break;
                pii to_remove = intersect(*first_possible, pii(slide.l, slide.r));
                num += to_remove.second - to_remove.first + 1;
                if (to_remove != *first_possible) // if something is left over add it to untouched
                    untouched.insert(pii(to_remove.second + 1, first_possible->second));
                untouched.erase(first_possible);
            }

            // now we redirect the drop clumps who go into our slide
            for (auto ite = drop_clumps.lower_bound(pii(slide.l, -1));
             ite != drop_clumps.end() && ite->first <= slide.r;
             ite = drop_clumps.lower_bound(pii(slide.l, -1))) {
                num += ite->second;
                drop_clumps.erase(ite);
            }

            if (num)
                drop_clumps.insert(pii(slide.dest, num));
        }
    }

    vector<pii> drop_clumps_vec(all(drop_clumps));
    vector<pii> untouched_vec(all(untouched));

    vector<int> csum_untouched(untouched.size());
    for (int i = 0; i < (int)untouched.size(); i++)
    {
        csum_untouched[i] += untouched_vec[i].second - untouched_vec[i].first + 1;
        if (i)
            csum_untouched[i] += csum_untouched[i - 1];
    }
    vector<int> csum_drop_clumps(drop_clumps.size());
    for (int i = 0; i < (int)drop_clumps_vec.size(); i++) {
        csum_drop_clumps[i] += drop_clumps_vec[i].second;
        if (i)
            csum_drop_clumps[i] += csum_drop_clumps[i - 1];
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        int out = 0;
        // add the drops first
        int right_dp = lower_bound(all(drop_clumps_vec), pii(b + 1, -1)) - drop_clumps_vec.begin() - 1;
        int left_dp = lower_bound(all(drop_clumps_vec), pii(a, -1)) - drop_clumps_vec.begin();
        if (right_dp >= left_dp && right_dp >= 0)
            out += csum_drop_clumps[right_dp];
        if (right_dp >= left_dp && left_dp)
            out -= csum_drop_clumps[left_dp - 1];
        
        // now we gotta add the untouched guys
        int right_untouched = lower_bound(all(untouched_vec), pii(b + 1, -1)) - untouched_vec.begin() - 1;
        int left_untouched = lower_bound(all(untouched_vec), pii(a, -1)) - untouched_vec.begin();
        if (left_untouched && untouched_vec[left_untouched - 1].second >= a)
            left_untouched--;

        if (right_untouched >= left_untouched && right_untouched >= 0) {
            out += csum_untouched[right_untouched];
            if (left_untouched)
                out -= csum_untouched[left_untouched - 1];

            out -= max(0, a - untouched_vec[left_untouched].first);
            out -= max(0, untouched_vec[right_untouched].second - b);
        }


        cout << out << "\n";
    }
}
