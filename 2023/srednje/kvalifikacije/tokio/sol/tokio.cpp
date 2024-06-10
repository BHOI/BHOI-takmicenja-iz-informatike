#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ARR_TYPE_ELEM 0
#define ARR_TYPE_QUERY 1

using namespace std;

struct range_struct {
    int s, e, l, r;
    int res_g, res_l;
};

struct elem_type {
    int val, type, query_inx, arr_inx;
};

inline bool sort_asc(const elem_type& a, const elem_type& b) {
    return a.val!=b.val?(a.val < b.val):(a.type > b.type);
}
inline bool sort_desc(const elem_type& a, const elem_type& b) {
    return a.val!=b.val?(a.val > b.val):(a.type > b.type);
}

// globalni niz za unos i parametri programa
int arr[100100], n, m;
range_struct ranges[100100];
// niz za fenwikovo stablo (jedno za trazenje > brojeva a drugo za <)
int fenw_l[1<<21]{0}, fenw_g[1<<21]{0};
// vektori koji sluze za spajanje niza brojeva i upita
vector< elem_type > arr_desc, arr_asc;

// dodavanje u fenkvikovo stablo
void fenw_add(int *fenw, int inx, int val=1) {
    while (inx < 1<<21) {
        fenw[inx] += val;
        inx += inx&(-inx);
    }
}

// dohvatanje iz fenvikovog stabla
int fenw_get(int *fenw, int range) {
    int r = 0;
    while (range) {
        r += fenw[range];
        range -= range&(-range);
    }
    return r;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr_asc.push_back({arr[i], ARR_TYPE_ELEM, -1, i});
        arr_desc.push_back({arr[i], ARR_TYPE_ELEM, -1, i});
    }
    for (int i = 0; i < m; ++i) {
        cin >> ranges[i].s >> ranges[i].e >> ranges[i].l >> ranges[i].r;
        arr_asc.push_back({ranges[i].l, ARR_TYPE_QUERY, i});
        arr_desc.push_back({ranges[i].r, ARR_TYPE_QUERY, i});
    }

    sort(arr_asc.begin(), arr_asc.end(), sort_asc);
    sort(arr_desc.begin(), arr_desc.end(), sort_desc);

    for (int i = 0; i < arr_asc.size(); ++i) {
        //cout << arr_asc[i].val << " ["<<arr_asc[i].type<<"]"<<endl;
    }

    for (int i = 0; i < arr_asc.size(); ++i) {
        if (arr_asc[i].type == ARR_TYPE_ELEM) {
            fenw_add(fenw_l, arr_asc[i].arr_inx+1);
            //cout << "insert: " << arr_asc[i].arr_inx+1 << endl;
        }
        else {
            int s_range = ranges[ arr_asc[i].query_inx ].s;
            int e_range = ranges[ arr_asc[i].query_inx ].e;
            int numValid = fenw_get(fenw_l, e_range+1) - fenw_get(fenw_l, s_range);
            ranges[ arr_asc[i].query_inx ].res_l = numValid;
            //cout << "For number " << arr_asc[i].val << ": " << numValid << "["<<e_range+1<<"-"<<s_range<<"]" << endl;
        }
    }
    for (int i = 0; i < arr_desc.size(); ++i) {
        if (arr_desc[i].type == ARR_TYPE_ELEM) {
            fenw_add(fenw_g, arr_desc[i].arr_inx+1);
            //cout << "insert: " << arr_desc[i].arr_inx+1 << endl;
        }
        else {
            int s_range = ranges[ arr_desc[i].query_inx ].s;
            int e_range = ranges[ arr_desc[i].query_inx ].e;
            int numValid = fenw_get(fenw_g, e_range+1) - fenw_get(fenw_g, s_range);
            ranges[ arr_desc[i].query_inx ].res_g = numValid;
            //cout << "For number " << arr_desc[i].val << ": " << numValid << endl;
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ranges[i].e-ranges[i].s+1 - (ranges[i].res_g+ranges[i].res_l) << endl;
    }

    return 0;
}
