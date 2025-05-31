#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void Rijesi(const vector <int> &ulaz, int k, vector <int> &rjesenje);
void RijesiBrutalno(const vector <int> &ulaz, int k, vector <int> &rjesenje);

int NajduziPodstring(int N, int K, int ulazNiz[], int izlazNiz[])
{
    vector <int> ulaz, izlaz;
 
    for (int i = 0;i < N; i++)
        ulaz.push_back(ulazNiz[i]);
 
 
    #ifdef BRUTALNO
    RijesiBrutalno(ulaz, K, izlaz);
    #endif // BRUTALNO
    #ifndef BRUTALNO
    Rijesi(ulaz, K, izlaz);
    #endif
 
    int n(izlaz.size());
 
    for (int i = 0; i < n; i++)
        izlazNiz[i] = izlaz[i];
 
    return n;
}
 
void Rijesi(const vector <int> &ulaz, int k, vector <int> &rjesenje)
{
    int n(ulaz.size());
    vector <int> pojave[100005];
 
    for (int i = 0; i < n; i++)
        pojave[ulaz[i]].push_back(i);
 
    int zadnjaPojava[100005]; // Drzi indeks preko kojeg se pristupa vektoru pojave
    fill(zadnjaPojava, zadnjaPojava + 100005, -1);
 
    int intervalStart(0), intervalEnd(0);
    int solStart(0), solLen(1);
 
    while(intervalEnd < n)
    {
        int i(intervalEnd); // Da bude malo lakse skontati
 
        zadnjaPojava[ulaz[i]]++;
 
        if (!(zadnjaPojava[ulaz[i]] < k || pojave[ulaz[i]] [zadnjaPojava[ulaz[i]] - k] < intervalStart))
            intervalStart = pojave[ulaz[i]] [zadnjaPojava[ulaz[i]] - k] + 1;
 
        if (intervalEnd - intervalStart + 1 > solLen)
        {
            solStart = intervalStart;
            solLen = intervalEnd - intervalStart + 1;
        }
 
        intervalEnd++;
    }
 
    rjesenje.resize(solLen);
    for (int i = solStart; i < (solStart + solLen); i++)
        rjesenje[i - solStart] = ulaz[i];
}
 
void RijesiBrutalno(const vector <int> &ulaz, int k, vector <int> &rjesenje)
{
    int n(ulaz.size());
    int brojPon[100005];
 
    int solStart(0), solLen(1);
 
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool nexti(false);
            fill (brojPon, brojPon + 100005, 0);
 
            for (int ii = i; ii <= j; ii++)
            {
                brojPon[ulaz[ii]]++;
 
                if (brojPon[ulaz[ii]] > k)
                {
                    nexti = true;
                    break;
                }
            }
 
            if (nexti)
                break;
            else if (j - i + 1 > solLen)
            {
                solStart = i;
                solLen = j - i + 1;
            }
        }
    }
 
    rjesenje.resize(solLen);
 
    for (int i = solStart; i < (solStart + solLen); i++)
        rjesenje[i - solStart] = ulaz[i];
}
