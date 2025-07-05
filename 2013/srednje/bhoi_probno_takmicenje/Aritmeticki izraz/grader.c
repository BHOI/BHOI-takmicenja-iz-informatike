#include <stdio.h>

int izracunaj(const char *izraz);

int main() {
	char izraz[1000001];
	if (fgets(izraz, 1000000, stdin) == NULL)
		fprintf(stderr, "Internal grader error: fgets failed!\n");
	else
		printf("%d\n", izracunaj(izraz));
	return 0;
}
