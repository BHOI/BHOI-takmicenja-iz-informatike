#include <cstdio>
#include <cstdlib>

using namespace std;

int br_poziva;
bool pogodjen;
int m;

int Pokusaj(int k) {
    ++br_poziva;
    if (k == m) {
        pogodjen = true;
        return 0;
    }
    else if (k > m) {
        pogodjen = false;
        return 1;
    }
    else {
        pogodjen = false;
        return -1;
    }
}

int main(int argc, char **argv) {

	FILE *fin, *fout, *fifo_in, *fifo_out;

	fin = fopen("input", "r");
	fout = fopen("output", "w");
	fifo_in = fopen(argv[1], "w");
	fifo_out = fopen(argv[2], "r");

	int a, b, max, tmp;
	tmp = fscanf(fin, "%d %d %d %d", &a, &b, &m, &max);
	fprintf(fifo_in, "%d %d\n", a, b);
	fflush(fifo_in);
	fprintf(fout, "ZapocniIgru(%d, %d)\n", a, b);
	int k;
	br_poziva = 0;
	pogodjen = false;
	while(fscanf(fifo_out, "%d", &k) == 1) {
		int p = Pokusaj(k);
		fprintf(fifo_in, "%d\n", p);
		fflush(fifo_in);
		fprintf(fout, "Pokušaj(%d) = %d\n", k, p);
	}
	if (pogodjen == false || br_poziva > max) {
		printf("0.00\n");
		if (pogodjen == false)
			fprintf(stderr, "Tajni broj nije pogođen.");
		else
			fprintf(stderr, "Tajni broj pogođen, ali u više od %d pokušaja.", max);
	}
	else {
		fprintf(stderr, "Tajni broj pogođen unutar %d pokušaja.", max);
		printf("1.00\n");
	}

	fclose(fin);
	fclose(fout);
	fclose(fifo_in);
	fclose(fifo_out);

	return 0;
}


