#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    vector<string> taken;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << a << " " << b << endl;
        string c, d;
        cin >> c >> d;
        if (c == a)
            a = d;
        else
            b = d;
    }
    cout << a << " " << b << endl;
}