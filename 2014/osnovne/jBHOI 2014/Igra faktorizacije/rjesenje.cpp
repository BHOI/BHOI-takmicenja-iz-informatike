#include <set>

using namespace std;

set<int> Q;

int IgraFaktorizacije(int M, int* P, int N)
{
    Q.clear();
    for (int i = 0; i < M; i++)
        for (int j = i; j < M; j++)
            Q.insert(P[i] * P[j]);
    int bro = 1;
    for (set<int>::iterator i = Q.begin(); i != Q.end(); i++)
    {
        if(bro == N)
            return *i;
        bro++;
    }
}
