#include <stdio.h>
#include <stdlib.h>

extern void DetekcijaAnomalija(long long, int, long long*);

long long *posAjvar, *aAjvar, nAjvar, modulAjvar;
int kAjvar, mAjvar;

int upit(long long x, long long L, long long R) {
	if(L > R) return 0;
	if(L < 1 || L > nAjvar || R < 1 || R > nAjvar) return 0;
	for(int i = 0; i < kAjvar+mAjvar; ++i) {
		if(L <= posAjvar[i] && posAjvar[i] <= R) {
			return aAjvar[i] <= x;
		}
	}
	if(R - L >= modulAjvar) return modulAjvar <= x;
	long long modL = L % modulAjvar, modR = R % modulAjvar;
	if(modL == 0) modL = modulAjvar;   
	if(modR == 0) modR = modulAjvar;
	if(modL <= modR) return modR <= x;
	return modulAjvar <= x;
}

int main() {
	int dummy = scanf("%lld %d %d %lld",&nAjvar,&kAjvar,&mAjvar,&modulAjvar);
	posAjvar = (long long*)malloc((kAjvar+mAjvar)*sizeof(long long));
	aAjvar = (long long*)malloc((kAjvar+mAjvar)*sizeof(long long));
	for(int i = 0; i < kAjvar+mAjvar; ++i) {
		dummy = scanf("%lld %lld",&posAjvar[i],&aAjvar[i]);
	}
	long long *anomalije = (long long*)calloc(kAjvar*sizeof(long long), sizeof(long long));
	DetekcijaAnomalija(nAjvar,kAjvar,anomalije);
	dummy = printf("AjvarJeIstinskiPlavKadHaberZaspamaRIkurs\n");
	for(int i = 0; i < kAjvar; ++i) {
		long long x = -1;
		for(int j = 0; j < kAjvar + mAjvar; ++j) {
			if(posAjvar[j] == anomalije[i]) {
				x = aAjvar[j];
				break;
			}
		}
		dummy = printf("%lld\n",x);
	}
	dummy = printf("GdjeImaAjvaraImaIIstine\n");
	return 0;
}
