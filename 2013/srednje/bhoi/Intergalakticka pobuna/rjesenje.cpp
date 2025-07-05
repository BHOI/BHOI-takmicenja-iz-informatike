#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 100005
char S[ MAXN ];
int n;

int solveN3( const char * S, int n ) {
	int maxlen = 0;

	for ( int i = 0; i < n; i++ ) {
		for ( int j = i + 1; j < n; j++ ) {
			int len = 0;
			while ( j + len < n && S[ i + len ] == S[ j + len ] ) len++;
			maxlen = max( maxlen, len );
		}
	}

	return maxlen;
}

// KMP O(N^2) worst-case
int P[ MAXN ];
int solveN2KMP( const char * S, int n ) {
	int maxlen = 0;

	for ( int pos = 0; pos < n; pos++ ) {
		const char * T = S + pos;
		const int N = n - pos;
		int k = 0;
		P[ 1 ] = 0;
		for ( int i = 2; i < N; i++ ) {
			while ( k > 0 && T[ i - 1 ] != T[ k ] ) k = P[ k ];
			if ( T[ i - 1 ] == T[ k ] ) k++;
			P[ i ] = k;
			maxlen = max( maxlen, k );
		}
	}

	return maxlen;
}

#define BIGPRIME 734567
#define STEP 265713
int hashTable[ BIGPRIME ];
int iteration[ BIGPRIME ];
int timerz = 0;

inline bool same( const char * S, const char * T, int len ) {
	for ( int i = 0; i < len; i++ ) {
		if ( S[ i ] != T[ i ] ) return 0;
	}
	return 1;
}

inline int insert( const char * S, int hash, int idx, int len ) {
	while ( iteration[ hash ] == timerz ) {
		if ( same( S + idx, S + hashTable[ hash ], len ) ) return 0;
		hash = ( hash + STEP ) % BIGPRIME;
	}
	hashTable[ hash ] = idx;
	iteration[ hash ] = timerz;
	return 1;
}

bool hashPass( const char * S, int n, int len ) {
	int hash = 0;
	int base = 1;
	for ( int i = 0; i < len; i++ ) {
		hash = ( 26 * hash + S[ i ] ) % BIGPRIME;
		if ( i < len - 1 ) base = ( base * 26 ) % BIGPRIME;
	}
	insert( S, hash, 0, len );
	for ( int i = len, start = 1; i < n; i++, start++ ) {
		hash = ( hash - base * S[ start - 1 ] ) % BIGPRIME;
		if ( hash < 0 ) hash += BIGPRIME;
		hash = ( 26 * hash + S[ i ] ) % BIGPRIME;
		if ( !insert( S, hash, start, len ) ) return 0;
	}
	return 1;
}

// Hashing O(N^2) expected worst-case
int solveN2hash( const char * S, int n ) {
	for ( int len = n - 1; len > 0; len-- ) {
		timerz++;

		if ( !hashPass( S, n, len ) ) return len;
	}
}

int solveNlogNBSHash( const char * S, int n ) {
	int left = 1, right = n - 1;
	while ( left <= right ) {
		timerz++;

		int mid = ( left + right ) / 2;

		if ( !hashPass( S, n, mid ) ) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return right;
}

int Analiza(int n, const char *poruka)
{
	//return solveN3(poruka, n);
	//return solveN2KMP(poruka, n);
	//return solveN2hash(poruka, n);
	return solveNlogNBSHash(poruka, n);
}
