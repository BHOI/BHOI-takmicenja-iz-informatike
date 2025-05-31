#include <vector>

using namespace std;

int Raspodjela(int N, int* T)
{
    long long s1(0);
    long long s2(0);
    long long suma(0);
    for (int i(0); i < N; i++)
        suma += T[i];
    int i(0), j(N - 1);
    while(1)
    {
        if(s1 + s2 == suma)
            return i;
        if(s1 <= s2)
        {
            s1 += T[i];
            i++;
        }
        else if (s2 < s1)
        {
            s2 += T[j];
            j--;
        }
    }
}
