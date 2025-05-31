#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXN 1024
#define MAXM 5
#define MAXPERM 120

#define SWAP(T,X,Y) { T tmp; tmp=X; X=Y; Y=tmp; }

int nextPerm(int n, int a[]) {
    int i,j,k,l;
    for (j=n-2; j>=0 && a[j] >= a[j+1]; j--);
    if (j < 0) return 0;
    for (l=n-1; l>j && a[j] >= a[l]; l--);
    SWAP(int,a[j],a[l])
    for (k=j+1, l=n-1; k<l; k++, l--)
       SWAP(int,a[k],a[l])
    return 1;
}

int max3(int x1, int x2, int x3)
{
		int x4 = (x1>x2)?x1:x2;
		return (x4>x3)?x4:x3;
}

int maxPal(int n, char rijec[])
{
    int i,j;
    int *mat[MAXN] = {0};

    for (i=0; i<n; i++)
    {
        mat[i] = (int*)calloc(MAXN,sizeof(int));
        mat[i][i] = 1;
    }

    for (i=1; i<n; i++)
	    for (j=0; j<n-i; j++)
	    	mat[j][i+j] = max3(	mat[j][i+j-1],
				mat[j+1][i+j],
				mat[j+1][i+j-1] + 2*(rijec[j] == rijec[i+j]));

    return mat[0][n-1];
}

int main()
{
    int i,j,m,n;
    int perm[MAXM];
    char rijec[MAXM][MAXN], niz[MAXN];
    int score, bestScore, nBestPerm = 0;

    FILE *fin = fopen("egipat.in", "r");
    FILE *fout = fopen("egipat.out", "w");

    fscanf(fin, "%d", &m);

    n = 0;
    for (i=0; i<m; i++)
    {
		fscanf(fin, "%s", rijec[i]);
		n += strlen(rijec[i]);
		perm[i] = i;
   	}

   	bestScore = MAXN+1;

    do
    {
		strcpy(niz, "");
		for (i=0; i<m; i++)
		    strcat(niz, rijec[perm[i]]);

		score = n - maxPal(n, niz);
		if (score < bestScore)
        {
		    nBestPerm=0;
		    bestScore = score;
		}
		if (score == bestScore)
		    nBestPerm++;
	}
    while (nextPerm(m, perm));

    fprintf(fout,"%d\n%d\n", bestScore, nBestPerm);

    fclose(fin);
    fclose(fout);
}
