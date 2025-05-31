#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100, MAXK = 10, INF = 1e9 + 1 + 1e-6;
int e[MAXN][MAXN], dist[MAXN][MAXN];

int NajmanjeVrijeme(int N, int M, int *u, int *v, int *w, int K, int *d, int **p, int s) {
	int n = N, m = M, k = K;
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < n; ++j) 
			dist[i][j] = i == j ? 0 : INF;
	for(int i = 0; i < m; ++i) {
		e[u[i]][v[i]] = e[v[i]][u[i]] = w[i];
		dist[u[i]][v[i]] = dist[v[i]][u[i]] = w[i];
	}
	vector <vector<int>> arrive(k, vector <int>(n, INF));
	for(int i = 0; i < k; ++i) {
		arrive[i][p[i][0]] = 0;
		for(int j = 1; j < d[i]; ++j) 
			arrive[i][p[i][j]] = arrive[i][p[i][j-1]] + e[p[i][j]][p[i][j-1]];
 	}
	for(int k = 0; k < n; ++k) 
		for(int i = 0; i < n; ++i) 
			for(int j = 0; j < n; ++j) 
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	int mini = INF;
	vector <int> perm(k);
	for(int i = 0; i < k; ++i) perm[i] = i;
	do {
		int cur = 0, u = s;
		for(int i = 0; i < k; ++i) {
			int v = perm[i], lo = 0, hi = d[v];
			while(lo < hi) {
				int mi = (lo + hi) >> 1;
				if(cur + dist[u][p[v][mi]] <= arrive[v][p[v][mi]]) hi = mi;
				else lo = mi + 1;
			} 
			if(hi == d[v]) {
				cur = INF;
				break;
			}
			cur = arrive[v][p[v][lo]];
			u = p[v][lo];
		}
		mini = min(mini, cur);
	} while(next_permutation(perm.begin(), perm.end()));
	return mini == INF ? -1 : mini;
}
