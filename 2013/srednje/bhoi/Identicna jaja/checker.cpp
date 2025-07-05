#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int br_bacanja;
int jaja_puklo;
int n, m, k;

bool BaciJaje(int i) {
    ++br_bacanja;
    if (jaja_puklo >= k && k > 0) {
      printf("0.00\n");
      fprintf(stderr, "Vaš program je pokušao koristiti više jaja nego što je imao na raspolaganju.\n");
      exit(0);
    }
    if (i < 0 || i >= n)  {
      printf("0.00\n");
      fprintf(stderr, "Vaš program je pokušao koristiti sprat koji ne postoji.\n");
      exit(0);
    }
    if (i > m) {
      ++jaja_puklo;
      return true;
    } else
      return false;
}

int main(int argc, char **argv) {

	FILE *fin, *fout, *fifo_in, *fifo_out;

	fin = fopen("input", "r");
	fout = fopen("output", "w");
	fifo_in = fopen(argv[1], "w");
	fifo_out = fopen(argv[2], "r");

	int t_max;
	fscanf(fin, "%d %d %d %d", &n, &k, &m, &t_max);
	fprintf(fifo_in, "%d %d\n", n, k);
	fflush(fifo_in);
	fprintf(fout, "PronadjiSprat(%d, %d)\n", n, k);
	int c;
	br_bacanja = 0;
	jaja_puklo = 0;
	while(fscanf(fifo_out, "%d", &c) == 1) {
		if (c == 0) {
			int i;
			fscanf(fifo_out, "%d", &i);
			bool r = BaciJaje(i);
			fprintf(fifo_in, "%d\n", (r ? 1 : 0));
			fflush(fifo_in);
			fprintf(fout, "BaciJaje(%d) = %s\n", i, (r ? "true" : "false"));
		}
		else if (c == 1) {
			int rezultat;
			fscanf(fifo_out, "%d", &rezultat);
			if (rezultat == m) {
				fprintf(fout, "rezultat = %d\n", rezultat);
				fprintf(fout, "bacanja = %d\n", br_bacanja);
				if (br_bacanja <= t_max) {
					printf("1.00\n");
					fprintf(stderr, "Vaš program je ispravno i optimalno odredio najviši sprat s kojeg jaje neće pući prilikom bacanja.\n");
					goto clean_n_exit;
				}
				else {
					printf("%f", pow(0.5, ((double)br_bacanja-t_max)/t_max));
					fprintf(stderr, "Vaš program je ispravno, ali ne i optimalno odredio najviši sprat s kojeg jaje neće pući prilikom bacanja.\n");
					goto clean_n_exit;
				}
			}
			else {
				printf("0.00\n");
				fprintf(stderr, "Vaš program nije ispravno odredio najviši sprat s kojeg jaje neće pući prilikom bacanja.\n");
				goto clean_n_exit;
			}
		}
		else
			break;
	}
	printf("0.00\n");
	fprintf(stderr, "Interna greška, potrebno je da obavijestite administratore takmičenja.\n");

clean_n_exit:
	fclose(fin);
	fclose(fout);
	fclose(fifo_in);
	fclose(fifo_out);

	return 0;
}


