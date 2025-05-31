#include <bits/stdc++.h>

using namespace std;

int a[50005], N;
vector<int> tree[4 * 50005];

void build(int lo, int hi, int pos) {
    if (lo == hi) {
        tree[pos].push_back(a[lo]);
        return;
    }
    int mid = (lo + hi) / 2;
    build(lo, mid, pos * 2);
    build(mid + 1, hi, pos * 2 + 1);
    merge(tree[2 * pos].begin(), tree[2 * pos].end(), tree[2 * pos + 1].begin(), tree[2 * pos + 1].end(), back_inserter(tree[pos]));
}

int cnt(int lo, int hi, int qlo, int qhi, int k, int pos) {
    if (lo >= qlo && hi <= qhi) {
        return (lower_bound(tree[pos].begin(), tree[pos].end(), k) - tree[pos].begin());
    }
    int mid = (lo + hi) / 2;
    if (qhi <= mid)
        return cnt(lo, mid, qlo, qhi, k, pos * 2);
    else if (qlo > mid)
        return cnt(mid + 1, hi, qlo, qhi, k, pos * 2 + 1);
    else
        return cnt(lo, mid, qlo, qhi, k, pos * 2) + cnt(mid + 1, hi, qlo, qhi, k, pos * 2 + 1);
}

int findKth(int l, int r, int k) {
    int lo = 0, hi = 50000;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        int cntLess = cnt(0, N - 1, l, r, mid, 1);
        if (cntLess > k)
            hi = mid - 1;
        else
            lo = mid;
    }
    return lo;
}

void update(int lo, int hi, int idx, int val, int pos) {
    if (lo == hi) {
        tree[pos].clear();
        tree[pos].push_back(val);
        return;
    }
    int mid = (lo + hi) / 2;
    if (idx <= mid)
        update(lo, mid, idx, val, pos * 2);
    else
        update(mid + 1, hi, idx, val, pos * 2 + 1);
    tree[pos].clear();
    merge(tree[2 * pos].begin(), tree[2 * pos].end(), tree[2 * pos + 1].begin(), tree[2 * pos + 1].end(), back_inserter(tree[pos]));
}

void medijana(int *A, int n, int *T, int *X, int *Y, int q, double *R) {
    for (int i = 0; i < n; i++) a[i] = A[i];
    N = n;
    build(0, n - 1, 1);
    int idx = 0;
    for (int k = 0; k < q; k++) {
        if (T[k] == 1) {
            A[X[k]] = Y[k];
            update(0, n - 1, X[k], Y[k], 1);
        }
        else {
            int len = Y[k] - X[k] + 1;
            if (len % 2 == 1) {
                R[idx] = findKth(X[k], Y[k], len / 2);
            }
            else {
                R[idx] = (findKth(X[k], Y[k], len / 2) + findKth(X[k], Y[k], len / 2 - 1)) / 2.0;
            }
            idx++;
        }
    }
}

