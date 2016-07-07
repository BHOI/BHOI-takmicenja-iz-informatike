#include <stdio.h>
#include <stdlib.h>

extern int NajmanjeVrijeme(int, int, int*, int*, int*, int, int*, int**, int);

int main() {
	int n, m, i, *u, *v, *w, k, *d, **p, s, j;
	scanf("%d %d",&n,&m);
	u = (int*)malloc(m * sizeof(int));
	v = (int*)malloc(m * sizeof(int));
	w = (int*)malloc(m * sizeof(int));
	for(i = 0; i < m; ++i) scanf("%d %d %d",&u[i],&v[i],&w[i]);
	scanf("%d",&k);
	d = (int*)malloc(k * sizeof(int));
	p = (int**)malloc(k * sizeof(int*));
	for(i = 0; i < k; ++i) {
		scanf("%d",&d[i]);
		p[i] = (int*)malloc(d[i] * sizeof(int));
		for(j = 0; j < d[i]; ++j) scanf("%d",&p[i][j]);
	}
	scanf("%d",&s);
	printf("%d\n",NajmanjeVrijeme(n, m, u, v, w, k, d, p, s));
	free(u);
	free(v);
	free(w);
	free(d);
	for(i = 0; i < k; ++i) free(p[i]);
	free(p);
	return 0;
}
