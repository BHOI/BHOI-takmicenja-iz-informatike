#include <stdio.h>
#include <stdlib.h>

int PronadjiSprat(int n, int k);

FILE *fifo_in, *fifo_out;

int BaciJaje(int i) {
	int r, tmp;
	tmp = fprintf(fifo_out, "0 %d\n", i);
	fflush(fifo_out);
	tmp = fscanf(fifo_in, "%d", &r);
	if (tmp == tmp)
	    return r;
}

int main(int argc, char **argv) {
	fifo_in = fopen(argv[2], "r");
	fifo_out = fopen(argv[1], "w");

	int n, k, tmp, rezultat;
	tmp = fscanf(fifo_in, "%d %d", &n, &k);
	rezultat = PronadjiSprat(n, k);
	tmp = fprintf(fifo_out, "1 %d\n", rezultat);
	fflush(fifo_out);

	fclose(fifo_in);
	fclose(fifo_out);
	
	if (tmp == tmp)
		return 0;
}
