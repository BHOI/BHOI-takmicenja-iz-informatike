#include <cstdio>
using namespace std;

const int MAXP = 1005;
int main (void) {
	int np; scanf ("%d", &np);
	int p[MAXP];

	int fp = 0;
	for (int i = 0; i < np; i++) {
        scanf ("%d", &p[i]);
        fp ^= p[i];
	}

	if (fp == 0)
	    printf ("Jok\n");
	else for (int i = 0; i < np; i++)
        if ((fp ^ p[i]) < p[i]) {
            printf ("%d %d\n", i + 1, fp ^ p[i]);
            break;
	    }

	return 0;
}
