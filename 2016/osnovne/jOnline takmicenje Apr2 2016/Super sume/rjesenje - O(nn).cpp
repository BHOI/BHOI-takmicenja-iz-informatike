#include <iostream>

using namespace std;

int main()
{
    long long n, s(0);

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            s+=j;
        }
    }

    cout << s;
}
