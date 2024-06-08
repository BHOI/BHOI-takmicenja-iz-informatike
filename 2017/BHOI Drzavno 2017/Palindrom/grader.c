#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* palindrom(int n, int *a, int *b, char *c);

int main()
{
    int n;
    int a, b;
    char c;

    scanf("%d", &n);

    int *x = (int*)malloc((n + 5) * sizeof(int));
    int *y = (int*)malloc((n + 5) * sizeof(int));
    char *z = (char*)malloc((n + 5) * sizeof(char));

    while (n--)
        scanf("%d %d %c", &x[n], &y[n], &z[n]);

    char *str = palindrom(n, x, y, z);

    printf("%s\n", str);

    free(x);
    free(y);
    free(z);
    free(str);

    return 0;
}

