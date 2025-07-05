#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef unsigned long ullong;
typedef vector < ullong > vull;
inline ullong fi ( ullong x ) {
    ullong i;
    double sol = x;
    vull V;
    for ( i = 2; i * i <= x && x > 1; ++i )
        if ( x % i == 0 ) {
            while ( x % i == 0 ) x /= i;
            V.push_back ( i );
        }
    if ( x != 1 ) V.push_back ( x );
    for ( vull :: iterator it = V.begin (); it != V.end (); ++it ) sol *= 1.00 - 1.00 / double ( *it );
    return ullong ( round ( sol ) );
}
int main () {
    freopen ( "relprost.in", "r", stdin );
    freopen ( "relprost.out", "w", stdout );
    ullong a, b, n, sum = 0;
    cin>>a>>b;
    for ( ; b >= a; --b ) sum += fi ( b );
    cout<<sum<<endl;
    return 0;
}
