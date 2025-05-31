#include <cstdio>
#include <cstdlib>
#include <ctime>
int Probaj(int x,int y);

//strategije
void random_napadi(int n,int m,int w);
void prava_strategija(int n,int m,int w);
void seq_napadi(int n,int m,int w);
void druga_strategija(int n,int m,int w);

void Napadaj(int n,int m,int w)
{
	//druga_strategija(n,m,w);
	//seq_napadi(n,m,w);
    prava_strategija(n,m,w);
}

void seq_napadi(int n,int m,int w)
{
    int c=0;
    for(int i=0;i<n && c<w;i++)
    {
        for(int j=0;j<m && c<w;j++)
            c+=Probaj(i+1,j+1);
    }
}

void random_napadi(int n,int m,int w)
{
    srand(time(0));
    int mat[50][50]={},c=0;
    while(c<w)
    {
        int x=rand()%n+1;
        int y=rand()%m+1;
        if(mat[x][y]==0)
            c+=Probaj(x,y);
        mat[x][y]=1;
    }
}

void prava_strategija(int n,int m,int w)
{
    int mat[51][51]={},nasao=-1,c=0;
    for(int i=0;i<n && nasao==-1;i++)
    {
        for(int j=w-1;j<m && nasao==-1;j+=w)
        {
            if(Probaj(i+1,j+1))
                mat[i][j]=1,nasao=i;
            else
                mat[i][j]=-1;
        }
    }
    c=1;
    int x=nasao,y=0,y1;
    for(int i=0;i<m;i++)if(mat[x][i]==1)y=i;
    y1=y+1;
    while(y1<m && c<w && mat[x][y1]!=-1 && Probaj(x+1,y1+1))y1++,c++;
    y1=y-1;
    while(y1>=0 && c<w && mat[x][y1]!=-1 && Probaj(x+1,y1+1))y1--,c++;
}

void druga_strategija(int n,int m,int w)
{
    int mat[51][51]={},nasao=-1,c=0;
    for(int i=0;i<n && nasao==-1;i++)
    {
        for(int j=w-1;j<m && nasao==-1;j+=w)
        {
            if(Probaj(i+1,j+1))
                mat[i][j]=1,nasao=i;
            else
                mat[i][j]=-1;
        }
    }
    c=1;
    int x=nasao;
    for(int i=m-1;i>=0 && c!=w;i--)
    {
		if(mat[x][i]==0)
			if(Probaj(x+1,i+1))c++;
	}
}
