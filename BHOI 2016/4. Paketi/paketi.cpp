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
	int mask = 0;
	dist[s][0] = 0;
	pq.push(qobj(s,0,0));
	for(map <int, int>::iterator it = S[s].begin(); it != S[s].end(); ++it) {
		mask |= it->second;
		if(dist[s][mask] > it->first) {
			dist[s][mask] = it->first;
			pq.push(qobj(s,it->first,mask));
		}
	}
	while(!pq.empty()) {
		qobj t = pq.top();
		pq.pop();
		if(t.t > dist[t.u][t.mask]) continue;
		if(t.mask == (1 << k) - 1) return t.t;
		for(int i = 0; i < n; ++i) {
			if(e[t.u][i] != -1) {
				int td = t.t + e[t.u][i];
				if(td < dist[i][t.mask]) {
					dist[i][t.mask] = td;
					pq.push(qobj(i, td, t.mask));
				}
				map <int, int>::iterator it;
				for(it = S[i].begin(); it != S[i].end(); ++it) 
					if(it->first >= td) break;
				mask = t.mask;
				for(; it != S[i].end(); ++it) {
					mask |= it->second;
					if(dist[i][mask] > it->first) {
						dist[i][mask] = it->first;
						pq.push(qobj(i, it->first, mask));
					}
				}
			}
		}
	}
	return -1;
}
