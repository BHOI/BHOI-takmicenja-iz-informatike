#include <stdio.h>
#include <stdlib.h>

int Analiza(int n, const char *poruka);

int main() {
	int dummy, n;
	char tmp[100];
	char *poruka;
	if (fgets(tmp, 100, stdin) == NULL)
		fprintf(stderr, "Internal grader error: fgets failed!\n");
	else {
		dummy = sscanf(tmp, "%d", &n);
		poruka = malloc(n+1);
		if (fgets(poruka, n+1, stdin) == NULL)
			fprintf(stderr, "Internal grader error: fgets failed!\n");
		else {
		  int res = Analiza(n, poruka);
			dummy = printf("%d\n", res);
		}
		free(poruka);
	}
	if (dummy == dummy)
    return 0;
}
