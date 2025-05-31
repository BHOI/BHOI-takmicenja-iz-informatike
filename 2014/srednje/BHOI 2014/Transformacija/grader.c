#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Jednostavan generator pseudo slucajnih brojeva
unsigned long seed = 123;
inline unsigned myrand() { 
  seed = (214013 * seed + 2531011);
  return (seed>>16)&0x7FFF;
}

// Vraca dvostruki srednji razmak k brojeva na segmentu [0,n] zaokruzen na stepen
// broja dva umanjen za jedan.
inline unsigned IzracunajMaxDeltu(int n, int k) {
	unsigned delta = round(n / k);
	delta |= delta >> 1;
	delta |= delta >> 2;
	delta |= delta >> 4;
	delta |= delta >> 8;
	delta |= delta >> 16;
	delta = delta == 0 ? 1 : delta;
	return delta;
}

int TransformisiNiz(int n, int* krajnji, int m, int* pocetni, int* transformacija);

int GenerisiSortiranNiz(int* arr, int n, int k) {
	unsigned max_delta = IzracunajMaxDeltu(n, k);
	arr[0] = (myrand() & max_delta) % (n - 1) + 1;
	int i;
	for (i = 1; i < k; i++) {
		arr[i] = arr[i - 1] + (myrand() & max_delta);
		if (arr[i] >= n) {
			return i;
		}
	}
	return k;
}

int main() {
	int seed, n, m, l, dummy;
	dummy = scanf("%u %d %d %d", &seed, &n, &m, &l);
	int *krajnji = (int*) malloc(n * sizeof(int)), *pocetni = (int*) malloc(m * sizeof(int)), *transformacija = (int*) malloc((n + m) * sizeof(int));
	n = GenerisiSortiranNiz(krajnji, l, n);
	m = GenerisiSortiranNiz(pocetni, l, m);
	int *krajnji_kopija = (int*) malloc(n * sizeof(int)), *pocetni_kopija = (int*) malloc(m * sizeof(int));
	memcpy(krajnji_kopija, krajnji, n * sizeof(int));
	memcpy(pocetni_kopija, pocetni, m * sizeof(int));
	int r = TransformisiNiz(n, krajnji_kopija, m, pocetni_kopija, transformacija);
	int i = 0, j = 0, k;
	for (k = 0; k < r; k++) {
		if (transformacija[k] == -1) {
			++j;
		} else if (transformacija[k] == 0) {
			if (i >= n || j >= m || krajnji[i] != pocetni[j]) {
				printf("Neispravna transformacija.\n");
				return 0;
			}
			++i; ++j;
		} else {
			if (i >= n || krajnji[i] != transformacija[k]) {
				printf("Neispravna transformacija.\n");
				return 0;
			}
			++i;
		}
	}
	if (i != n || j != m) {
		printf("Neispravna transformacija.\n");
	} else {
		printf("Ispravna transformacija u %d koraka.\n", r);
	}
	return dummy != dummy;
}
