#include <stdio.h>
#include <stdlib.h>

int MaksimalnaZarada (int n, const char *rudnik);

int main() {
	int dummy, n;
	char tmp[100];
	char *rudnik;
	if (fgets(tmp, 100, stdin) == NULL)
		fprintf(stderr, "Internal grader error: fgets failed!\n");
	else {
		dummy = sscanf(tmp, "%d", &n);
		rudnik = malloc(n+1);
		if (fgets(rudnik, n+1, stdin) == NULL)
			fprintf(stderr, "Internal grader error: fgets failed!\n");
		else {
		  int res = MaksimalnaZarada(n, rudnik);
			dummy = printf("%d\n", res);
		}
		free(rudnik);
	}
	if (dummy == dummy)
    return 0;
}
