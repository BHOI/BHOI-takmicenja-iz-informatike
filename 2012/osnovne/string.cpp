#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
char S[200005], P[200005];

int cur[30], needed[30], cur_distinct = 0, needed_distinct = 0;

int main() {
	int num = 0;
	scanf("%d%d%s%s", &n, &m, S, P);
	for (int i = 0; i < m; i++) {
		if ( needed[ P[i] - 'A' ] == 0 ) needed_distinct++;
		needed[ P[i] - 'A' ]++;
	}
	for (int i = 0; i < m; i++) {
		cur[ S[i] - 'A' ]++;
		if ( cur[ S[i] - 'A' ] == needed[ S[i] - 'A' ] ) cur_distinct++;
	}
	if ( cur_distinct == needed_distinct ) num++;
	for (int i = m; i < n; i++) {
		if ( cur[ S[i - m] - 'A' ] == needed[ S[i - m] - 'A' ] ) cur_distinct--;
		cur[ S[i - m] - 'A' ]--;
		
		cur[ S[i] - 'A' ]++;
		if ( cur[ S[i] - 'A' ] == needed[ S[i] - 'A' ] ) cur_distinct++;
		if ( cur_distinct == needed_distinct ) num++;
	}
	printf("%d\n", num);
	return 0;
}
