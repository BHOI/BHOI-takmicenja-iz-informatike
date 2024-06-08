extern int upit(long long, long long, long long);

void DetekcijaAnomalija(long long n, int k, long long *anomalije) { //treba da prodje vremenski prva 2 subtaska, tako nastimati time limit
	long long *ano = new long long[n+1]; 
	for(long long i = 1; i <= n; ++i) {
		long long lo = 1, hi = 1e16 + 2;
		while(lo < hi) {
			long long mid = (lo + hi) >> 1;
			if(upit(mid,i,i)) hi = mid;
			else lo = mid+1;
		}
		ano[i] = lo;
	}
	for(int i = 0; i < k; ++i) {
		long long maxi = -1, idx = -1;
		for(long long j = 1; j <= n; ++j) {
			if(ano[j] > maxi) {
				maxi = ano[j];
				idx = j;
			}
		}
		ano[idx] = -1;
		anomalije[i] = idx;
	}
}
