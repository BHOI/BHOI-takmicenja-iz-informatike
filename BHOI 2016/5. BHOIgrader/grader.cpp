#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

int main()
{
    void Slicni( char * A[], int N, int M, char * S[], int Q, int R[], int K );
	
    int n, m, q, k;
    scanf( "%d%d%d%d", &n, &m, &q, &k );
    char ** A = new char * [ n ];
    char ** S = new char * [ q ];
    int * R = new int[ q ];
    for ( int i = 0; i < n; i++ ) A[ i ] = new char[ m + 1 ];
    for ( int i = 0; i < q; i++ ) S[ i ] = new char[ m + 1 ];
    for ( int i = 0; i < n; i++ ) scanf( "%s", A[ i ] );
    for ( int i = 0; i < q; i++ ) scanf( "%s", S[ i ] );
    Slicni( A, n, m, S, q, R, k );
    for ( int i = 0; i < q; i++ ) {
        printf( "%d\n", R[ i ] );
    }
    return 0;
}
