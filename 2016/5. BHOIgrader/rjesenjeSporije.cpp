#include <vector>

void Slicni( char * A[], int N, int M, char * S[], int Q, int R[], int K ){
    // Preprocesiranje
    std::vector< int > * razliciti;
    razliciti = new std::vector< int > [ N ];
    for ( int i = 1; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( A[ 0 ][ j ] != A[ i ][ j ] ) razliciti[ i ].push_back( j );
        }
    }
    
    // Query
    for ( int l = 0; l < Q; l++ ) {
        R[ l ] = 0;
        bool razlika[ 51 ] = {};
        for ( int j = 0; j < M; j++ ) if ( A[ 0 ][ j ] != S[ l ][ j ] ) razlika[ j ] = true, R[ l ]++;
        int startNum = R[ l ];
        if ( R[ l ] <= K ) R[ l ] = 1; else R[ l ] = 0;
        
        for ( int i = 1; i < N; i++ ) {
            int num = startNum;
            for ( int j = 0; j < razliciti[ i ].size(); j++ ) {
                if ( razlika[ razliciti[ i ][ j ] ] == false ) num++;
                else if ( A[ i ][ razliciti[ i ][ j ] ] == S[ l ][ razliciti[ i ][ j ] ] ) num--;
            }
            if ( num <= K ) R[ l ]++;
        }
    }
}