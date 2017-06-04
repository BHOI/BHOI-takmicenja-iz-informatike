#include <stdio.h>
#include <stdlib.h>

void medijana(int *A, int n, int *T, int *X, int *Y, int q, double *R);

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int *A = (int*)malloc((n+5) * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int *T = (int*)malloc((q+5) * sizeof(int));
    int *X = (int*)malloc((q+5) * sizeof(int));
    int *Y = (int*)malloc((q+5) * sizeof(int));
    int upiti = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &T[i], &X[i], &Y[i]);
        if (T[i] == 2) upiti++;
    }
    double *R = (double*)malloc((upiti+5) * sizeof(double));
    medijana(A, n, T, X, Y, q, R);
    for (int i = 0; i < upiti; i++) {
        printf("%.1f ", R[i]);
    }
    free(A);
    free(T);
    free(X);
    free(Y);
    free(R);
}

