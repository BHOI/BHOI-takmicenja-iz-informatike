#include <iostream>
using namespace std;

void printajDimenzije(int, int, int, int, int, int);

int main() 
{
    int x1, y1, a1, b1, a2, b2;
    cin >> x1 >> y1 >> a1 >> b1 >> a2 >> b2;
    printajDimenzije(x1, y1, a1, b1, a2, b2);
    return 0;
}

void printajDimenzije(int x1, int y1, int a1, int b1, int a2, int b2) 
{
    if (a2 > a1 || b2 > b1) 
    {
        cout << -1 << endl;
    } 
    else 
    {
        int x2 = x1 + a1 / 2 - a2 / 2;
        int y2 = y1 + b1 / 2 - b2 / 2;
        cout << x2 << " " << y2 << endl;
    }
}
