#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 200009;
const int MAXSEG = 800009;

// Stablo segmenata: svaki cvor sadrzi liste grana aktivnih u tom intervalu
vector<pair<int, int> > segEdges[MAXSEG];

// DSU sa undo podrskom (union by rank, bez path compression)
int dsPar[MAXN];
int dsRnk[MAXN];

struct Change {
    int *ptr;
    int val;
};
stack<Change> chStack;

int dsFind(int x) {
    while (dsPar[x] != x) {
        x = dsPar[x];
    }
    return x;
}

void dsUnion(int x, int y) {
    x = dsFind(x);
    y = dsFind(y);
    if (x == y) return;
    if (dsRnk[x] < dsRnk[y]) {
        int tmp = x; x = y; y = tmp;
    }
    Change c;
    c.ptr = &dsPar[y]; c.val = dsPar[y];
    chStack.push(c);
    dsPar[y] = x;
    if (dsRnk[x] == dsRnk[y]) {
        Change c2;
        c2.ptr = &dsRnk[x]; c2.val = dsRnk[x];
        chStack.push(c2);
        dsRnk[x]++;
    }
}

void rollBack(int savedSize) {
    while ((int)chStack.size() > savedSize) {
        Change top = chStack.top();
        chStack.pop();
        *top.ptr = top.val;
    }
}

// Dodaj granu u stablo segmenata za interval [ql, qr]
void segAdd(int node, int lo, int hi, int ql, int qr, int u, int v) {
    if (qr < lo || hi < ql) return;
    if (ql <= lo && hi <= qr) {
        segEdges[node].push_back(make_pair(u, v));
        return;
    }
    int mid = (lo + hi) / 2;
    segAdd(2 * node, lo, mid, ql, qr, u, v);
    segAdd(2 * node + 1, mid + 1, hi, ql, qr, u, v);
}

int a[MAXN], b[MAXN];
vector<int> hasA[MAXN]; // cvorovi sa a[u] == c
vector<int> hasB[MAXN]; // cvorovi sa b[u] == c

bool ANS;
int N, M;
int seenStamp[MAXN]; // za provjeru dostiznosti; ne resetuje se po test-primjeru
int curStamp;

// DFS po segmentnom stablu
void segSolve(int node, int lo, int hi) {
    int savedSize = (int)chStack.size();

    for (int i = 0; i < (int)segEdges[node].size(); i++) {
        dsUnion(segEdges[node][i].first, segEdges[node][i].second);
    }

    if (lo == hi) {
        int c = lo;
        curStamp++;
        // Oznaci korijene komponenti koje imaju cvor sa a[u] == c
        for (int i = 0; i < (int)hasA[c].size(); i++) {
            seenStamp[dsFind(hasA[c][i])] = curStamp;
        }
        // Provjeri da li svaki cvor sa b[u] == c pripada oznacenoj komponenti
        for (int i = 0; i < (int)hasB[c].size(); i++) {
            if (seenStamp[dsFind(hasB[c][i])] != curStamp) {
                ANS = false;
            }
        }
    } else {
        int mid = (lo + hi) / 2;
        segSolve(2 * node, lo, mid);
        if (ANS) segSolve(2 * node + 1, mid + 1, hi);
    }

    rollBack(savedSize);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;

        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= N; i++) {
            cin >> b[i];
        }

        ANS = true;
        for (int i = 1; i <= N; i++) {
            if (b[i] > a[i]) {
                ANS = false;
            }
            hasA[a[i]].push_back(i);
            hasB[b[i]].push_back(i);
            dsPar[i] = i;
            dsRnk[i] = 0;
        }

        // Ucitaj grane; ako je ANS vec false, samo ih procitaj
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            if (ANS) {
                // Grana je aktivna za pritisak c ako max(b[u],b[v]) <= c <= min(a[u],a[v])
                int ql = max(b[u], b[v]);
                int qr = min(a[u], a[v]);
                if (ql <= qr) {
                    segAdd(1, 1, N, ql, qr, u, v);
                }
            }
        }

        if (ANS) {
            segSolve(1, 1, N);
        }

        cout << (ANS ? 1 : 0) << "\n";

        // Ocisti za sljedeci test-primjer
        for (int i = 1; i <= 4 * N; i++) {
            segEdges[i].clear();
        }
        for (int i = 1; i <= N; i++) {
            hasA[i].clear();
            hasB[i].clear();
        }
    }
    return 0;
}
