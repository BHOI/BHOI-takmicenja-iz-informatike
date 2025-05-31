#include <iostream>

using namespace std;

int main()
{
    int d, s, k, n;
    cin >> d >> s >> k;

    for(int i=s;i>0;i--)
    {
        n=i;
        if(s%i==0 && d%i==0) break;
    }

    cout << k+(s/n);

    return 0;
}
