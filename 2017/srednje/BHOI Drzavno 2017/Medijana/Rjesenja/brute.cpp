#include <bits/stdc++.h>

using namespace std;

int a[10005];

void medijana(int *A, int n, int *T, int *X, int *Y, int q, double *R) {
    int idx = 0;
    for (int k = 0; k < q; k++) {
        if (T[k] == 1) {
            A[X[k]] = Y[k];
        }
        else {
            int j = 0;
            for (int i = X[k]; i <= Y[k]; i++) {
                a[j++] = A[i];
            }
            sort(a, a + j);
            int len = j;
            if (len % 2 == 1) {
                R[idx] = a[len/2];
            }
            else {
                R[idx] = (a[len/2] + a[len/2-1]) / 2.0;
            }
            idx++;
        }
    }
}
