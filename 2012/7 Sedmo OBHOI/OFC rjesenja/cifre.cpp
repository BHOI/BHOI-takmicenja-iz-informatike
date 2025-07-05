#include <iostream>
#include <stdio.h>
using namespace std;
typedef unsigned long long ull;
ull cifre ( ull n, ull c ) {
    ull cnt = 0;
    while ( n ) {
        if ( n % 10 == c ) ++cnt;
        n /= 10;
    }
    return cnt;
}
int main () {
    freopen ( "cifre.in", "r", stdin );
    freopen ( "cifre.out", "w", stdout );
    ull n, k, c, x = 1;
    cin >> n >> k >> c;
    //++n;
    while ( cifre ( n, c ) < k ) {
        if ( ( n / x ) % 10 != c ) n += x * 1;
        else x *= 10;
    }
    cout << n << endl;
    return 0;
}
