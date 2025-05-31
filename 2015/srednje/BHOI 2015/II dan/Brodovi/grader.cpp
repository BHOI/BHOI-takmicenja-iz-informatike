#include <stdio.h>
#include <string.h>
#include <math.h>

static int _mat[52][52],R,C,W,his_score;

void Napadaj(int,int,int);

int Valid()//vraca broj uzastopno pogodjenih ili -1 nemoguce
{
    int red=-1;
    int i,j;
    for( i=0;i<R;i++)
    {
        for( j=0;j<C;j++)
        {
            if(_mat[i][j]==1 && (red!=-1 && red!=i))return -1;
            if(_mat[i][j]==1)red=i;
        }
    }
    for( i=0;i<R;i++)
        for( j=0;j<C;j++)
        {
            if(_mat[i][j]==1)
            {
                int jeste=0;
                while(j<C && _mat[i][j++]==1)
                    jeste++;
                return jeste;
            }
        }
    return 0;
}

int KolikoMoze()
{
    if(Valid()==W)return 1;
    if(Valid()>W || Valid()<0)return 0;
    int red=-1;
    int i,j;
    for( i=0;i<R && red==-1;i++)
        for( j=0;j<C && red==-1;j++)
            if(_mat[i][j]==1)red=i;
    int sluc=0;
    if(red!=-1)
    {
        for( j=0;j<C-W+1;j++)
        {
            int moze=1;
            for( i=0;i<W;i++)
                if(_mat[red][j+i]==-1)moze=0;
            for( i=j+W;i<C;i++)
                if(_mat[red][i]==1)moze=0;
            for( i=0;i<j;i++)
                if(_mat[red][i]==1)moze=0;
            sluc+=moze;
        }
    }
    else
    {
        for( i=0;i<R;i++)
        {
            int mog=0;
            for( j=0;j<C;j++)
            {
                if(_mat[i][j]==-1)mog=0;
                else mog++;
                if(mog>=W)sluc++;
            }
        }
    }
    return sluc;
}

void Print()
{
	int i,j;
    for( i=0;i<R;i++)
    {
        for( j=0;j<C;j++)
            printf("%2d ",_mat[i][j]);
        puts("");
    }
}

int Probaj(int x,int y)//vraca 0 ako je miss, 1 ako je pogodak
{
    his_score++;
    x--;y--;//posto je 1 indeksirano
    if(x<0 || y<0 || x>=R || y>=C)return -1;
    if(_mat[x][y]==-1)return 0;//ako je vec miss bio
    if(_mat[x][y]== 1)return 1;//ako je pogodak
    _mat[x][y]=-1;
    int miss=KolikoMoze();
    if(miss==0)
        _mat[x][y]=1;
    return _mat[x][y]==1;
}

void Pokreni(int r,int c,int w)
{
    R=r;C=c;W=w;
    memset(_mat,0,sizeof _mat);
    his_score=0;
    Napadaj(R,C,W);
}

int main()
{
    int r,c,w;
    if(scanf("%d %d %d",&r,&c,&w)!=3)printf("-1\n");
	printf("%d %d %d\n",r,c,w);
	Pokreni(r,c,w);
	printf("---Pocetak---$$NemaSanseRealno\n");
	if(Valid()==W)printf("%d\n",his_score);
	else printf("%d\n",-1);
	printf("---Kraj---$$\n");
    return 0;
}
