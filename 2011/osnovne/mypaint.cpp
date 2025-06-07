#include <cstdio>

using namespace std;

int main()
{
    freopen("mypaint.in", "r", stdin);
	freopen("mypaint.out", "w", stdout);
	bool polje[1000][1000];
    int n, m;
    scanf("%i %i", &m, &n);
    while (n--)
    {
        int red1, kolona1, red2, kolona2;
        scanf("%i %i %i %i", &red1, &kolona1, &red2, &kolona2);
        for (int i = red1; i <= red2; i++)
            for (int j = kolona1; j <= kolona2; j++)
                polje[i-1][j-1] = !polje[i-1][j-1];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            if (polje[i][j])
                printf("*");
            else
                printf(".");
        printf("\n");
    }
}
