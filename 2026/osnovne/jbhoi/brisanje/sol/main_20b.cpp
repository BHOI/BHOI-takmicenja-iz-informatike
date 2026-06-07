#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Rjesenje za podzadatak 3 (a_i <= 1000): coin-change po sortiranim distinktnim vrijednostima
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> freq(1001, 0);
    for (int i = 0; i < n; i++)
        freq[a[i]]++;

    vector<bool> can(1001, false);
    can[0] = true;

    int removable = 0;
    for (int val = 1; val <= 1000; val++)
    {
        if (freq[val] == 0)
            continue;
        if (can[val])
        {
            // Sve kopije su suvisne
            removable += freq[val];
        }
        else
        {
            // Jedna kopija ostaje, ostale su suvisne
            removable += freq[val] - 1;
            // Dodajemo val u coin-change DP
            for (int v = val; v <= 1000; v++)
            {
                if (can[v - val])
                    can[v] = true;
            }
        }
    }

    cout << removable << endl;
    return 0;
}
