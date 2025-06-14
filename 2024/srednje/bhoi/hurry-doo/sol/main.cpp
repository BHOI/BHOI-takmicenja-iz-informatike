#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>

typedef long long ll;

using namespace std;

int INT_MIN = -2147483648;

//Implementacija Node structurea za persistent segmentno stablo
//Svrha koristenja pointera je memorijska optimizacija
struct Node {
    pair<int, int> val;
    Node *lc, *rc;

    Node(pair<int, int> _val) : val(_val), lc(nullptr), rc(nullptr) {}

    Node(Node *_lc, Node *_rc) : lc(_lc), rc(_rc), val({INT_MIN, -1}) {
        if (lc) val = max(val, lc->val);
        if (rc) val = max(val, rc->val);
    }
} * persist_roots[500001];

int n, x, y, k, csum[500001]; // Varijable definisemo globalno radi lakseg koristenja u metodama

// Metoda za Node struct koja gradi segmentno stablo
Node *build(int l = 1, int r = n) {
    if (l == r) return new Node({csum[l], l});
    int mid = (l + r) / 2;
    return new Node(build(l, mid), build(mid + 1, r));
}

// Metoda koja vraca maksimalnu vrijednost rangea u persistent segmentnom stablu
pair<int, int> query(Node *node, int a, int b, int l = 1, int r = n) {
    if (!node || r < a || l > b) return {INT_MIN, -1};
    if (l >= a && r <= b) return node->val;
    int mid = (l + r) / 2;
    return max(query(node->lc, a, b, l, mid), query(node->rc, a, b, mid + 1, r));
}

// Metoda koja "skida" vrijednost na pozicij pos kako bi eliminisali ponavljanje istih kombinacija paketa
Node *update(Node *node, int pos, int l = 1, int r = n) {
    if (l == r) return nullptr;
    int mid = (l + r) / 2;
    if (pos > mid) return new Node(node->lc, update(node->rc, pos, mid + 1, r));
    return new Node(update(node->lc, pos, l, mid), node->rc);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> x >> y;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        csum[i] = csum[i - 1] + a; //pravimo niz kumulativnih suma jer je najbolji izbor segmenta paketa za neki indeks i dat formulom max(csum[j] : j izmedju i + x - 1 do i + y - 1) - csum[i - 1]
    }

    // S obzirom da nam za formulu treba range query, koristiti cemo segmentno stablo, medjutim, kako bismo eliminisali kombinacije
    // koje smo vec izabrali, morati cemo koristiti persistent segmentno stablo jer u slucaju koristenja samo jedne verzije segmentnog
    // eliminisali bismo vrijednosti koje se potencijalno preklapaju sa nekim drugim optimalnim izborima kombinacija paketa.
    // Ako imamo poseban root node za svaki moguci pocetni indeks uzastopnog niza paketa, onda bismo mogli samo brisati krajnje tacke
    // svakog izabranog maksimalnog intervala i updateat odgovarajuci root node.
    Node *init_root = build();
    for (int i = 1; i <= n - x + 1; i++) persist_roots[i] = init_root;

    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n - x + 1; i++) {
        pair<int, int> res = query(persist_roots[i], i + x - 1, i + y - 1);
        pq.push({res.first - csum[i - 1], i});
        // Maksimalne vrijednosti cemo drzati u priority queueu zbog kasnijeg updateanja uslijed uklanjanja izabranih segmenata
    }
    ll rjesenje = 0;
    while (k--) {
        int v, i;
        v = pq.top().first, i = pq.top().second;
        pq.pop();
        rjesenje += v;
        pair<int, int> res = query(persist_roots[i], i + x - 1, i + y - 1);
        persist_roots[i] = update(persist_roots[i], res.second);
        // Prvobitno na priority queue dodajemo maksimalni izbor za svaki indeks individualno, a kasnije skidanjem intervala s nekog indeksa dodajemo iducu maksimalnu
        // vrijednost za taj indeks
        res = query(persist_roots[i], i + x - 1, i + y - 1);
        pq.push({res.first - csum[i - 1], i});

    }
    cout << rjesenje;
    return 0;
}