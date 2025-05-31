#include <bits/stdc++.h>
using namespace std;

struct qobj {
	int u, t, mask;
	qobj() {}
	qobj(int U, int T, int MASK) : u(U), t(T), mask(MASK) {}
};

struct comp { bool operator() (const qobj& a, const qobj& b) {return a.t > b.t;} };
const int MAXN = 100, MAXK = 10, INF = 1e9 + 1 + 1e-6;
int e[MAXN][MAXN], dist[MAXN][1<<MAXK];
map <int, int> S[MAXN];

int NajmanjeVrijeme(int N, int M, int *u, int *v, int *w, int K, int *d, int **p, int s) {
	int n = N, m = M, k = K;
	memset(e, -1, sizeof(e));
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < (1 << k); ++j) 
			dist[i][j] = INF;
	for(int i = 0; i < n; ++i) S[i].clear();
	for(int i = 0; i < m; ++i) e[u[i]][v[i]] = e[v[i]][u[i]] = w[i];
	for(int i = 0; i < k; ++i) {
		int ct = 0, *r = p[i];
		S[r[0]][0] |= (1 << i); //d[i] > 0 za svako i
		for(int j = 1; j < d[i]; ++j) {
			ct += e[r[j]][r[j-1]];
			S[r[j]][ct] |= (1 << i);
		}
	}
	priority_queue <qobj, vector <qobj>, comp> pq;
	dist[s][0] = 0;
	pq.push(qobj(s,0,0));
	while(!pq.empty()) {
		qobj t = pq.top();
		pq.pop();
		if(t.mask == (1 << k) - 1) return t.t;
		if(t.t > dist[t.u][t.mask]) continue;
		map <int, int>::iterator it;
		for(it = S[t.u].begin(); it != S[t.u].end(); ++it) 
			if(it->first >= t.t) break;
		int mask = t.mask;
		for(; it != S[t.u].end(); ++it) {
			mask |= it->second;
			if(dist[t.u][mask] > it->first) {
				dist[t.u][mask] = it->first;
				pq.push(qobj(t.u, it->first, mask));
			}
		}
		for(int i = 0; i < n; ++i) {
			if(e[t.u][i] != -1) {
				if(t.t + e[t.u][i] < dist[i][t.mask]) {
					dist[i][t.mask] = t.t + e[t.u][i];
					pq.push(qobj(i, t.t + e[t.u][i], t.mask));
				}
			}
		}
	}
	return -1;
}
