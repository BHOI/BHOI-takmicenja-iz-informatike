#include <iostream>
using namespace std;

const int MAXN = 200009;
int a[MAXN], b[MAXN];
bool inA[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; i++) cin >> a[i];
        for (int i = 1; i <= N; i++) cin >> b[i];
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
        }

        // Provjera 1: b[u] <= a[u] za sve cvorove (pritisak se moze samo smanjivati)
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            if (b[i] > a[i]) { ok = false; break; }
        }
        if (!ok) { cout << "0\n"; continue; }

        // Provjera 2: skup vrijednosti b mora biti podskup skupa vrijednosti a
        // U kompletnom grafu svaki cvor je direktno povezan s drugim,
        // pa se pritisak c moze prenijeti direktno na bilo koji cvor
        // (jednim potezom, bez posrednih cvorova)
        for (int i = 1; i <= N; i++) inA[i] = false;
        for (int i = 1; i <= N; i++) inA[a[i]] = true;
        for (int i = 1; i <= N; i++) {
            if (!inA[b[i]]) { ok = false; break; }
        }

        cout << (ok ? 1 : 0) << "\n";
    }
    return 0;
}
