// prvo morate razumjeti bitonic merge proceduru opisanu u main_bitonic_merge
// na najlakše razumijevanje tačnosti algoritma, pretpostavimo da je 
// veličina niza stepen dvice
// prvo iskorisite bitonic sort proceduru na prvoj polovini niza i onda
// sortirajte drugu polovinu naopako

// sada je ovaj niz bitonic i možemo iskoristit bitonic merge da sortiramo niz
// ovaj kod nosi otprilike 70 poena
#include <bits/stdc++.h>
using namespace std;

using Gate = pair<int, int>;
using Network = vector<Gate>;

static int greatestPowerOfTwoLessThan(int x) {
    int p = 1;
    while (p < x) p <<= 1;
    return p >> 1;
}

static void addComparator(Network &net, int i, int j, bool ascending) {
    if (ascending) {
        net.emplace_back(i, j);
    } else {
        net.emplace_back(j, i);
    }
}

static void bitonicMerge(Network &net, int lo, int len, bool ascending) {
    if (len <= 1) return;

    int k = greatestPowerOfTwoLessThan(len);
    for (int i = lo; i < lo + len - k; ++i) {
        addComparator(net, i, i + k, ascending);
    }

    bitonicMerge(net, lo, k, ascending);
    bitonicMerge(net, lo + k, len - k, ascending);
}

static void bitonicSort(Network &net, int lo, int len, bool ascending) {
    if (len <= 1) return;

    int k = greatestPowerOfTwoLessThan(len);
    bitonicSort(net, lo, k, !ascending);
    bitonicSort(net, lo + k, len - k, ascending);
    bitonicMerge(net, lo, len, ascending);
}

static Network bitonicSortNetwork(int n) {
    Network net;
    bitonicSort(net, 0, n, true);
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

        Network net = bitonicSortNetwork(n);
        cout << net.size() << '\n';
        for (auto [a, b] : net) {
            cout << a << ' ' << b << '\n';
        }
    }
}
