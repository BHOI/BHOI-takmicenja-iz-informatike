#include <bits/stdc++.h>

using namespace std;

int quickPartition(int a[], int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    int v = a[lo];
    while (true) {
        // find item on lo to swap
        while (a[++i] < v)
            if (i == hi) break;

        // find item on hi to swap
        while (v < a[--j])
            if (j == lo) break;      // redundant since a[lo] acts as sentinel

        // check if pointers cross
        if (i >= j) break;

        swap(a[i], a[j]);
    }

    // put partitioning item v at a[j]
    swap(a[lo], a[j]);

    // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
    return j;
}

int quickSelect(int a[], int n, int k) {
    int lo = 0, hi = n - 1;
    while (hi > lo) {
        int i = quickPartition(a, lo, hi);
        if      (i > k) hi = i - 1;
        else if (i < k) lo = i + 1;
        else return a[i];
    }
    return a[lo];
}

int a[50005];

void medijana(int *A, int n, int *T, int *X, int *Y, int q, double *R) {
    int idx = 0;
    for (int k = 0; k < q; k++) {
        if (T[k] == 1) {
            A[X[k]] = Y[k];
        }
        else {
            int len = Y[k] - X[k] + 1;
            int j = 0;
            for (int i = X[k]; i <= Y[k]; i++) {
                a[j++] = A[i];
            }
            if (len % 2 == 1) {
                R[idx] = quickSelect(a, len, len/2);
            }
            else {
                R[idx] = (quickSelect(a, len, len/2) + quickSelect(a, len, len/2-1)) / 2.0;
            }
            idx++;
        }
    }
}


