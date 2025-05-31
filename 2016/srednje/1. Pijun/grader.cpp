#include <cstdio>
#include <cassert>

using namespace std;

void PremjestiPijuna (int N, int X, int Y, int P, char potezi[], int rjesenje[]);

int main()
{
    int N, X, Y, P;
    scanf("%d", &N);
    scanf("%d %d", &X, &Y);
    scanf("%d ", &P);
    char* potezi = new char [P+5];
    for (int i = 0; i < P; i++)
        potezi[i] = getchar();
    potezi[P]=0;
    int rjesenje[2];
    PremjestiPijuna (N, X, Y, P, potezi, rjesenje);
    printf("%d %d\n", rjesenje[0], rjesenje[1]);
    return 0;
}
