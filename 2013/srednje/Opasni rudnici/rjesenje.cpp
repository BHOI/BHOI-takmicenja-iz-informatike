#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int MaksimalnaZaradaDP (int n, const char *rudnik)
{
    int m((-1+sqrt(1+8*n))/2), poc(0);
    vector<vector<int> >  matrica(m);
    for (int i=0; i<m; i++)
    {
        matrica[i].resize(i+1);
        for (int j=0; j<i+1; j++)
            matrica[i][j]=rudnik[poc++];
    }
    for (int i=m-1; i>=1; i--)
        for (int j=0; j<i; j++)
            matrica[i-1][j]=matrica[i-1][j]+max(matrica[i][j], matrica[i][j+1]);
    return matrica[0][0];
}

bool Backtrack (const vector<vector<int> > &a, int i, int j, int n, int &suma, int &maksimum)
{
    suma=suma+a[i][j];
    if(suma>maksimum) maksimum=suma;
    if (i+1>=n || j+1>=n)
    {
        suma=suma-a[i][j];
        i--;
        return false;
    }
    if (i==n-1 && j==n-1) return true;
    Backtrack(a, i+1, j, n, suma, maksimum);
    Backtrack(a, i+1, j+1, n, suma, maksimum);
    suma=suma-a[i][j];
    i--;
    return false;
}
int MaksimalnaZaradaBacktrack (int n, const char *rudnik)
{
	int m((-1+sqrt(1+8*n))/2), poc(0), maksimum(0), suma(0);
    vector<vector<int> >  matrica(m);
    for (int i=0; i<m; i++)
    {
        matrica[i].resize(i+1);
        for (int j=0; j<i+1; j++)
            matrica[i][j]=rudnik[poc++];
    }
    Backtrack (matrica, 0, 0, m, suma, maksimum);
    return maksimum;
}

int Dijkstra (int brcv, int briv, vector<vector<int> > mat)
{   int trcv, trmaks, bro(1), ind, ukupnimaks(0);
    vector<int> rjduz(brcv + 1, 0), susjedi(brcv + 1, 0);
    rjduz[1]=mat[1][3];
    trcv=1;
    while(bro<brcv)
    {
        for (int i=1; i<briv; i++)
            if(mat[i][1]==trcv && susjedi[mat[i][2]]<mat[i][3]+rjduz[trcv])
                susjedi[mat[i][2]]=mat[i][3]+rjduz[trcv];
        trmaks=0;
        for (int i=1; i<brcv+1; i++)
            if(susjedi[i]>trmaks)
            {
                trmaks=susjedi[i];
                ind=i;
            }
        if(trmaks>ukupnimaks) ukupnimaks=trmaks;
        susjedi[ind]=-1;
        rjduz[ind]=trmaks;
        trcv=ind;
        bro++;
    }
    return ukupnimaks;
}
int MaksimalnaZaradaDijkstra (int n, const char *rudnik)
{
    int m((-1+sqrt(1+8*n))/2), poc(0);
    vector<vector<int> >  matrica(n);
    vector<vector<int> >  cvorovi(n);
    for (int i=0; i<m; i++)
    {
        matrica[i].resize(i+1);
        cvorovi[i].resize(i+1);
        for (int j=0; j<i+1; j++)
        {
            matrica[i][j]=rudnik[poc];
            cvorovi[i][j]=poc+1;
            poc++;
        }
    }
    int brcv(n), briv(2), dva(2), bro(2);
    for (int i=0;i<m-1;i++)
        {briv=briv+dva; dva=dva+2;}
    vector<vector<int> >  mat(briv, vector<int> (4));
    mat[1][1]=1; mat[1][2]=1; mat[1][3]=matrica[0][0];
    for (int i=0; i<m-1; i++)
        for (int j=0; j<i+1; j++)
            {mat[bro][1]=cvorovi[i][j]; mat[bro][2]=cvorovi[i+1][j]; mat[bro][3]=matrica[i+1][j]; bro++;
             mat[bro][1]=cvorovi[i][j]; mat[bro][2]=cvorovi[i+1][j+1]; mat[bro][3]=matrica[i+1][j+1]; bro++;}
    int rezultat(Dijkstra (brcv, briv, mat));
    return rezultat;
}

int MaksimalnaZarada (int n, const char *rudnik) {
	return MaksimalnaZaradaDP(n, rudnik);
	//return MaksimalnaZaradaBacktrack(n, rudnik);
	//return MaksimalnaZaradaDijkstra(n, rudnik);
}
