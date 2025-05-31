#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long a, b, s = 0, div;
    cin >> a >> b;
    if(a < b)
        cout << 0 << endl;
    else if(a == b)
        cout << "Beskonacno" << endl;
    else
    {
        for (int i = 1; i <= sqrt(a - b); i++)
        {
            if((a - b) % i == 0 && i > b)
                s++;
            if((a - b) % i == 0 && a - b > b * i && i * i != a - b)
                s++;
        }
        cout << s << endl;
    }
    return 0;
}
