/*
batcher sorting network algoritam nosi 90 poena
broj gateova je O(n log^2(n)) kao i batcher ali je konstanta bolja

Suština batcher sorting algoritma je slijedeća. Ako neki niz ima duzinu djeljivu sa 4
i mi sortiramo prvu polovinu niza, drugu polovinu nizu, podskup parnih elemenata 
i podskup neparnih elemenata. Onda samo trebamo dodati gateova na
(0,1), (2, 3), .. da dobijemo sortiran niz. Za tačnu analizu pogledajte link dole.
https://math.mit.edu/~shor/18.310/batcher.pdf
*/

#include <bits/stdc++.h>
using namespace std;

using Gate = pair<int, int>;
using Network = vector<Gate>;

static void addComparator(Network &net, int i, int j, int n) {
    if (i < n && j < n) net.emplace_back(i, j);
}

static void oddEvenMerge(Network &net, int lo, int len, int stride, int n) {
    int doubleStride = 2 * stride;
    if (doubleStride < len) {
        oddEvenMerge(net, lo, len, doubleStride, n);
        oddEvenMerge(net, lo + stride, len, doubleStride, n);

        for (int i = lo + stride; i + stride < lo + len; i += doubleStride) {
            addComparator(net, i, i + stride, n);
        }
    } else {
        addComparator(net, lo, lo + stride, n);
    }
}

static void oddEvenSort(Network &net, int lo, int len, int n) {
    if (len <= 1) return;

    int half = len / 2;
    oddEvenSort(net, lo, half, n);
    oddEvenSort(net, lo + half, half, n);
    oddEvenMerge(net, lo, len, 1, n);
}

static Network batcherNetwork(int n) {
    int powerOfTwo = 1;
    while (powerOfTwo < n) powerOfTwo <<= 1;

    Network net;
    oddEvenSort(net, 0, powerOfTwo, n);
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

        Network net = batcherNetwork(n);
        cout << net.size() << '\n';
        for (auto [a, b] : net) {
            cout << a << ' ' << b << '\n';
        }
    }
}
