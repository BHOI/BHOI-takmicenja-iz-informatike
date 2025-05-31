#include <iostream>
#include <cassert>

using namespace std;

int AlfaKoeficijent(int W, char *C);

int main()
{
    int W;
    cin >> W;
    char *C = new char [W];
    for (int i = 0; i < W; i++)
    	cin >> C[i];
    cout << AlfaKoeficijent(W, C) << endl;
    return 0;
}
