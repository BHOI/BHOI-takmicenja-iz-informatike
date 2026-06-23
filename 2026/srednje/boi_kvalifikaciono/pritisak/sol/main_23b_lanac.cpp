#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int LOG = 18;

// Sparse table za range min od a i range max od b u lancu
// Redovi su pozicije (1..N), kolone su stepen dvojke
vector<vector<int>> spMinA;
vector<vector<int>> spMaxB;
vector<int> lgArr;

void buildSparse(const vector<int> &a, const vector<int> &b, int n) {
    spMinA.assign(n + 1, vector<int>(LOG));
    spMaxB.assign(n + 1, vector<int>(LOG));
    for (int i = 1; i <= n; i++) {
        spMinA[i][0] = a[i];
        spMaxB[i][0] = b[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            spMinA[i][j] = min(spMinA[i][j-1], spMinA[i + (1 << (j-1))][j-1]);
            spMaxB[i][j] = max(spMaxB[i][j-1], spMaxB[i + (1 << (j-1))][j-1]);
        }
    }
}

int queryMinA(int l, int r) {
    int k = lgArr[r - l + 1];
    return min(spMinA[l][k], spMinA[r - (1 << k) + 1][k]);
}

int queryMaxB(int l, int r) {
    int k = lgArr[r - l + 1];
    return max(spMaxB[l][k], spMaxB[r - (1 << k) + 1][k]);
}

// Provjeri da li je pozicija i u lancu zadovoljiva.
// srcByVal[c] = sortirane pozicije gdje a[pos] == c (1-indeksirano)
bool checkPos(int i, const vector<int> &a, const vector<int> &b,
              const vector<vector<int>> &srcByVal) {
    int target = b[i];
    if (a[i] == b[i]) return true;

    // Trazi izvor lijevo: najveci l <= i sa a[l] == target,
    // takav da min_a[l..i] >= target i max_b[l..i] <= target.
    // Kako l raste prema i, interval se suzava pa su uvjeti samo bolji.
    // Dakle dovoljno je provjeriti samo najblizeg l <= i.
    const vector<int> &srcs = srcByVal[target];
    {
        int lo = 0, hi = (int)srcs.size() - 1, best = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (srcs[mid] <= i) { best = srcs[mid]; lo = mid + 1; }
            else hi = mid - 1;
        }
        if (best != -1 && queryMinA(best, i) >= target && queryMaxB(best, i) <= target)
            return true;
    }

    // Trazi izvor desno: najmanji r >= i sa a[r] == target
    {
        int lo = 0, hi = (int)srcs.size() - 1, best = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (srcs[mid] >= i) { best = srcs[mid]; hi = mid - 1; }
            else lo = mid + 1;
        }
        if (best != -1 && queryMinA(i, best) >= target && queryMaxB(i, best) <= target)
            return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Predobradi logaritme
    lgArr.resize(200001);
    lgArr[1] = 0;
    for (int i = 2; i <= 200000; i++) lgArr[i] = lgArr[i / 2] + 1;

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> a(N + 1), b(N + 1);
        for (int i = 1; i <= N; i++) cin >> a[i];
        for (int i = 1; i <= N; i++) cin >> b[i];

        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Provjera: b[i] <= a[i] za sve cvorove
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            if (b[i] > a[i]) { ok = false; break; }
        }
        if (!ok) { cout << "0\n"; continue; }

        // Rekonstruisi redoslijed lanca (od jednog kraja do drugog)
        int start = -1;
        for (int i = 1; i <= N; i++) {
            if ((int)adj[i].size() <= 1) { start = i; break; }
        }

        vector<int> order;
        order.reserve(N);
        order.push_back(start);
        int prev = -1, cur = start;
        while ((int)adj[cur].size() > 0) {
            int nxt = -1;
            for (int j = 0; j < (int)adj[cur].size(); j++) {
                if (adj[cur][j] != prev) { nxt = adj[cur][j]; break; }
            }
            if (nxt == -1) break;
            prev = cur;
            cur = nxt;
            order.push_back(cur);
        }

        // Remapuj a i b na pozicije u lancu (1-indeksirano)
        vector<int> aChain(N + 1), bChain(N + 1);
        for (int i = 0; i < N; i++) {
            aChain[i + 1] = a[order[i]];
            bChain[i + 1] = b[order[i]];
        }

        buildSparse(aChain, bChain, N);

        // Za svaku vrijednost c, sortirane pozicije gdje aChain[pos] == c
        vector<vector<int>> srcByVal(N + 1);
        for (int i = 1; i <= N; i++) srcByVal[aChain[i]].push_back(i);
        // Vektori su vec sortirani jer iteriramo i od 1 do N

        for (int i = 1; i <= N && ok; i++) {
            if (!checkPos(i, aChain, bChain, srcByVal)) ok = false;
        }

        cout << (ok ? 1 : 0) << "\n";
    }
    return 0;
}
