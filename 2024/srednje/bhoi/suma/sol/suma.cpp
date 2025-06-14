#include <iostream>
#include <vector>
#include <list>

using namespace std;
int M = 1000000007;
int fac[1000001]; // fac[i] = i! mod M
int inv[1000001]; // inv[i] = 1/i mod M (inverz iz teksta zadatka)
int fiv[1000001]; // fiv[i] = 1/(i!) mod M (inverz od fac[i]) 

long long int coeff(vector<int> A, vector<int> B)
{
    // Broj putanja od tacke B do tacke A
    // Pretpostavljeno je da je prije ovoga provjereno da je B[i] <= A[i] za sve i
    int s = 0;
    long long int p = 1;
    for (int i = 0; i < A.size(); i++)
    {
        s += A[i]-B[i];
        p = (p*fiv[A[i]-B[i]])%M;
    }
    return (p*fac[s])%M;
}

int main()
{
    fac[0] = 1; fac[1] = 1;
    inv[0] = 1; inv[1] = 1;
    fiv[0] = 1; fiv[1] = 1;
    for (long long int i = 2; i <= 1000000; i++)
    {
        long long int t = (M+i)/i;
        inv[i] = (t*inv[t*i-M])%M;
        fac[i] = (i*fac[i-1])%M;
        fiv[i] = (inv[i]*(long long int)(fiv[i-1]))%M;
    }

    int n, q;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    cin >> q;
    list<vector<int> > L;
    for (int i = 0; i < q; i++)
    {
        bool b = 0;
        vector<int> V(n);
        for (int j = 0; j < n; j++) cin >> V[j];

        for (auto it = L.begin(); it != L.end(); ++it)
        {
            // Topolosko sortiranje stabala
            b = 1;
            for (int j = 0; b && j < n; j++) // Provjera gdje se V moze smjestiti u L kako bi ostalo topoloski sortirano
                b = (V[j] <= (*it)[j]);

            if (!b) continue;
            L.insert(it, V);
            break;
        }
        if (!b) L.insert(L.end(), V);
    }
    L.insert(L.end(), A);
    // Kako je sada topoloski sortirano onda vrijedi sljecece:
    // Za sva stabla X i Y za koja vrijedi X[i] <= Y[i] za sve i, onda je X prije Y u listi L

    int i = 0;
    int R[q+1]; // R[i] = broj dobrih putanja do i-tog stabla (odnosno cilja, u slucaju R[q])
    vector<int> U(n);
    for (int j = 0; j < n; j++) U[j] = 1;
    for (auto it = L.begin(); it != L.end(); ++it)
    {
        int j = 0;
        R[i] = coeff(*it, U);
        //cout << R[i];
        for (auto jt = L.begin(); jt != it; ++jt)
        {
            bool b = 1;
            for (int k = 0; b && k < n; k++)
                b = ((*jt)[k] <= (*it)[k]);

            if (b) R[i] = (R[i]+(long long int)M-((R[j]*coeff(*it, *jt))%M))%M; // Znacenje ove linije:
            // Ako se moze doci od j-tog do i-tog stabla onda se broj dobrih putanja do i-tog stabla smanjuje za 
            // (broj dobrih putanja do j-tog stabla)*(broj putanja od j-tog do i-tog stabla).
            j++;
        }

        i++;
    }

    cout << R[q];
}
