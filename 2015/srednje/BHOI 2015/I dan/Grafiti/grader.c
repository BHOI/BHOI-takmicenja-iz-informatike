#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* NajboljiGrafit(int, int[]);
    int V, P[62], i;
    scanf("%d", &V);
    for (i = 0; i < 62; i++)
	scanf("%d", &P[i]);
    printf("%s", NajboljiGrafit(V, P));
    return 0;
}
