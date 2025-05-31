#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int d, pos, s = 0, dif;
    string input;
    cin >> d >> pos;
    cin.clear();
    cin.ignore(10000, '\n');
    getline(cin, input);
    if(pos > d / 2)
        pos = d - pos + 1;
    int l = 9999999, r = -1;
    for (int i = 0; i < d / 2; i++)
        if(input[i] != input[d - i - 1])
        {
            dif = abs(input[i] - input[d - i - 1]);
            if(dif > 13)
                dif = 26 - dif;
            s += dif;
            if(i < pos - 1 && i < l)
                l = i;
            if(i > pos - 1 && i > r)
                r = i;
        }
    if(r == -1 && l == 9999999)
        cout << s <<endl;
    else if(r == -1)
        cout << s + pos - l - 1 << endl;
    else if(l == 9999999)
        cout << s + r - pos + 1 << endl;
    else
        cout << s + 2 * min(pos - l - 1, r - pos + 1) + max(pos - l - 1, r - pos + 1) << endl;
    return 0;
}
