int dajBrojJedinica( unsigned long long * brojJedinica, unsigned long long x ) {
    int num = 0;
    while ( x ) {
        int bitmask = x & ( 0xffff );
        num += brojJedinica[ bitmask ];
        x >>= 16;
    }
    return num;
}

int dajLogTwo( unsigned long long * LogTwo, unsigned long long x ) {
    int num = 0;
    while ( x ) {
        int bitmask = x & ( 0xffff );
        num += LogTwo[ bitmask ];
        x >>= 16;
        if ( x ) num += 16;
    }
    return num;
}

void Slicni( char * A[], int N, int M, char * S[], int Q, int R[], int K ){
    // Preprocesiranje
    unsigned long long * hammingBitmasks = ( unsigned long long *) malloc( N * sizeof( unsigned long long ) );
    memset( hammingBitmasks, 0, sizeof( hammingBitmasks[ 0 ] ) * N );
    for ( int i = 1; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( A[ 0 ][ j ] != A[ i ][ j ] ) hammingBitmasks[ i ] |= ( 1ull << ( 63 - j ) );
        }
    }

    // Pomocni nizovi za bitmaske
    unsigned long long brojJedinica[ (1 << 16) ];
    for ( int i = 0; i < ( 1 << 16 ); i++ ) {
        brojJedinica[ i ] = 0;
        int j = i;
        while ( j ) {
            brojJedinica[ i ]++;
            j -= ( (~j) + 1 ) & j;
        }
    }
    unsigned long long logTwo[ (1 << 16) ] = {};
    for ( int i = 0; i < 16; i++ ) logTwo[ ( 1 << i ) ] = i;
    for ( int i = 3; i < ( 1 << 16 ); i++ ) {
        if ( logTwo[ i ] == 0 ) logTwo[ i ] = logTwo[ i - 1 ];
    }
    
    // Query
    for ( int l = 0; l < Q; l++ ) {
        R[ l ] = 0;
        hammingBitmasks[ 0 ] = 0;
        for ( int j = 0; j < M; j++ ) if ( A[ 0 ][ j ] != S[ l ][ j ] ) hammingBitmasks[ 0 ] |= ( 1ull << ( 63 - j ) ), R[ l ]++;
        if ( R[ l ] <= K ) R[ l ] = 1; else R[ l ] = 0;
        
        for ( int i = 1; i < N; i++ ) {
            unsigned long long greskeNaRazlicitomMjestu = hammingBitmasks[ 0 ] ^ hammingBitmasks[ i ];
            unsigned long long greskeNaIstomMjestu = hammingBitmasks[ 0 ] & hammingBitmasks[ i ];
            int brojRazlicitih = dajBrojJedinica( brojJedinica, greskeNaRazlicitomMjestu );
            int brojIstih = dajBrojJedinica( brojJedinica, greskeNaIstomMjestu );
            
            if ( brojRazlicitih > K ) continue;
            else if ( brojRazlicitih + brojIstih <= K ) R[ l ]++;
            else {
                unsigned long long temp = greskeNaIstomMjestu;
                int brojPravihGresakaNaIstomMjestu = 0;
                while ( temp ) {
                    int lastIdx = 63 - dajLogTwo( logTwo, ( (~temp) + 1 ) & temp );
                    if ( A[ i ][ lastIdx ] != S[ l ][ lastIdx ] ) {
                        brojPravihGresakaNaIstomMjestu++;
                    }
                    temp -= ( (~temp) + 1 ) & temp;
                    if ( brojPravihGresakaNaIstomMjestu + brojRazlicitih > K ) break;
                }
                if ( brojPravihGresakaNaIstomMjestu + brojRazlicitih <= K ) {
                    R[ l ]++;
                }
                else continue;
            }
        }
    }
}