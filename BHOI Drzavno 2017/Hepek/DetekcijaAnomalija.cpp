#include <stdlib.h>
extern int upit(long long, long long, long long);

void DetekcijaAnomalija(long long n, int k, long long *anomalije) {
	long long *anom = (long long*)malloc(sizeof(long long) * k);
	for(int i = 0; i < k; ++i) {
		long long lomax = 0, himax = 1e16 + 2;
		while(lomax < himax) { //trazimo maksimalan element u nizu(iskljucujuci dosadasnje anomalije) binarnom pretragom
			long long mid = (lomax + himax) >> 1;
			int flag = 1;
			for(int j = 0; j <= i; ++j) {
				long long last = (j == 0 ? 1 : (anom[j-1]+1)); 
				long long neu = (j == i ? n : (anom[j]-1));
				if(last <= neu && !upit(mid,last,neu)) {
					flag = 0;
					break;
				} 
 			}
			if(flag) himax = mid;
			else lomax = mid + 1;
		}
		long long maxi = lomax;
		for(int j = 0; j <= i; ++j) { //pronalazimo izmedju koje 2 anomalije se nalazi max cijelog niza
			long long last = (j == 0 ? 1 : (anom[j-1]+1)); 
			long long neu = (j == i ? n : (anom[j]-1));
			if(last <= neu && !upit(maxi-1,last,neu)) { 
				long long low = last, high = neu;
				while(low < high) { //binarnom pretragom nalazimo indeks na kom se max element nalazi
					long long mid = (low + high) >> 1;
					if(!upit(maxi-1,low,mid)) high = mid;
					else low = mid + 1;
				}
				anomalije[i] = anom[i] = low; //zapisujemo sljedecu anomaliju
				break;
			}
		}
		int idx = i;
		while(idx > 0 && anom[idx] < anom[idx-1]) {
			long long tmp = anom[idx];
			anom[idx] = anom[idx-1];
			anom[idx-1] = tmp;
			--idx;
		}
	}
}
