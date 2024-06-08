using namespace std;

void PremjestiPijuna(int N, int X, int Y, int P, char potezi[], int rjesenje[])
{
    for (int i = 0; i < P; i++)
    {
        if (potezi[i] == 'u')
            Y++;
        else if (potezi[i] == 'd')
            Y--;
        else if (potezi[i] == 'r')
            X++;
        else
            X--;
        if (X == N + 1)
            X = 1;
        else if (X == 0)
            X = N;
        if (Y == N + 1)
            Y = 1;
        else if (Y == 0)
            Y = N;
    }
    rjesenje[0] = X;
    rjesenje[1] = Y;
}
