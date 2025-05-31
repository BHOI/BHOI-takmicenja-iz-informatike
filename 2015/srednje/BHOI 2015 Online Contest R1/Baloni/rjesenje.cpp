#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if(a > b)
        swap(a, b);
    if(b > c)
        swap(b, c);
    if(a > b)
        swap(a, b);
    if((a + b) * 2 <= c)
        cout << a + b << endl;
    else
        cout << (a + b + c) / 3 << endl;
    return 0;
}


