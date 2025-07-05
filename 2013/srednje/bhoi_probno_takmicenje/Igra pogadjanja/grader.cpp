#include <cstdio>
#include <cstdlib>

using namespace std;

void ZapocniIgru(int a, int b);

FILE *fifo_in, *fifo_out;

int Pokusaj(int k) {
	int p, tmp;
	tmp = fprintf(fifo_out, "%d\n", k);
	fflush(fifo_out);
	tmp = fscanf(fifo_in, "%d", &p);
	return p;
}

int main(int argc, char **argv) {
	fifo_in = fopen(argv[2], "r");
	fifo_out = fopen(argv[1], "w");

	int a, b, tmp;
	tmp = fscanf(fifo_in, "%d %d", &a, &b);
	ZapocniIgru(a, b);

	fclose(fifo_in);
	fclose(fifo_out);

	return 0;
}


