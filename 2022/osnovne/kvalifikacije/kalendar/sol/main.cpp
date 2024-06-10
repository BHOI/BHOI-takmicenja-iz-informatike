#include <iostream>
#include <math.h>
using namespace std;

bool prestupna(int x)
{
    if (x % 400 == 0 || x % 4 == 0 && x % 100 != 0)
        return true;
    return false;
}

int s[2100];
int mjeseci[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dani[13];
void init()
{
    int suma = 0;
    for (int i = 1900; i <= 2040; i++)
    {
        suma += prestupna(i) ? 366 : 365;
        s[i] = suma;
    }
    for (int i = 1; i < 13; i++)
        dani[i] = dani[i - 1] + mjeseci[i];
}

int y, m, d;
int yy, mm, dd;

int main()
{
    init();
    scanf("%d:%d:%d", &y, &m, &d);
    scanf("%d:%d:%d", &yy, &mm, &dd);

    int d1 = s[y - 1] + dani[m - 1] + d - 1;
    if (prestupna(y) && m >= 3)
        d1++;

    int d2 = s[yy - 1] + dani[mm - 1] + dd - 1;
    if (prestupna(yy) && mm >= 3)
        d2++;

    cout << abs(d1 - d2) << endl;

    return 0;
}