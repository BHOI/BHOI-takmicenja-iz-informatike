#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;

    int R[1024];
    for (int i = 0; i < 1024; i++)
        R[i] = 0;

    for (int i = 0; i < n; i++)
    {
        long long int t;
        int k = 0;
        cin >> t;

        while (t)
        {
            switch (t%10)
            {
                case 0: k = k|1;   break;
                case 1: k = k|2;   break;
                case 2: k = k|4;   break;
                case 3: k = k|8;   break;
                case 4: k = k|16;  break;
                case 5: k = k|32;  break;
                case 6: k = k|64;  break;
                case 7: k = k|128; break;
                case 8: k = k|256; break;
                case 9: k = k|512; break;
            }
            t = t/10;
        }

        R[k]++;
        //cout << k << " " << R[k] << endl;
    }

    long long int r = 0;
    for (int i = 1; i < 1024; i++)
    {
        r += (R[i]*(long long int)(R[i]-1))/2;
        for (int j = i+1; j < 1024; j++)
            if (i&j)
                r += R[i]*(long long int)R[j];
    }

    cout << r;

    return 0;
}
