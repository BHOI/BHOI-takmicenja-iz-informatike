#include <cstdio>

using namespace std;

int Analiza(int n, const char *poruka);

int main() {
	int dummy, n;
	char tmp[100];
	char *poruka;
	if (fgets(tmp, 100, stdin) == NULL)
		fprintf(stderr, "Internal grader error: fgets failed!\n");
	else {
		dummy = sscanf(tmp, "%d", &n);
		poruka = new char[n+1];
		if (fgets(poruka, n+1, stdin) == NULL)
			fprintf(stderr, "Internal grader error: fgets failed!\n");
		else {
		  int res = Analiza(n, poruka);
			dummy = printf("%d\n", res);
		}
		delete[] poruka;
	}
	if (dummy == dummy)
    return 0;
}
