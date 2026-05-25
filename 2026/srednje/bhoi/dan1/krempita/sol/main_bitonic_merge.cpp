/*
ovo rješenje nosi 20 poena.
Poenta je samo merge proceduru Bitonic sort algoritma.

Ta procedura sortira bitonic niz, odnosno niz koji je ili valley ili peak niz.
Dodatno, veličina niza mora biti stepen dvice za najjednostavniju verziju algoritma.
Ako dodamo gateova na mjestima (0, n/2), (1, n/2 + 1), .. (n / 2 - 1, n - 1) obje
polovine će biti bitonic, i na lijevoj strani su svi manji elementi.
Sada samo moramo istu proceduru uraditi na obje polovice i dobiti cemo sortirani niz.
Ovaj algoritam je O(nlogn) i koristi puno manje gateova nego lijeva granica funkije f
opisane u statementu.
*/

#include <bits/stdc++.h>
using namespace std;

using Gate = pair<int, int>;
using Network = vector<Gate>;

static int greatestPowerOfTwoLessThan(int x) {
    int p = 1;
    while (p < x) p <<= 1;
    return p >> 1;
}

static void bitonicMerge(Network &net, int lo, int len) {
    if (len <= 1) return;

    int k = greatestPowerOfTwoLessThan(len);
    for (int i = lo; i < lo + len - k; ++i) {
        net.emplace_back(i, i + k);
    }

    bitonicMerge(net, lo, len - k);
    bitonicMerge(net, lo + len - k, k);
}

static Network bitonicMergeNetwork(int n) {
    Network net;
    bitonicMerge(net, 0, n);
    return net;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        Network net = bitonicMergeNetwork(n);
        cout << net.size() << '\n';
        for (auto [a, b] : net) {
            cout << a << ' ' << b << '\n';
        }
    }
}
