#include <iostream>

using namespace std;

int main()
{
    int br(0);
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++) if(s[i]=='G') br++;
    cout << br;
    return 0;
}
