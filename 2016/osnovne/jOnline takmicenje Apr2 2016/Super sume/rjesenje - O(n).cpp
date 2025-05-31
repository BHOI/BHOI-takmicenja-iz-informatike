#include <iostream>

using namespace std;

int main()
{
    long long n, s(0);

    cin >> n;

    n++;

    for(int i=1;i<n;i++)
    {
        s+=i*(n-i);
    }

    cout << s;
}
