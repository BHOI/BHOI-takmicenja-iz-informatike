#include <bits/stdc++.h>
using namespace std;
extern int pogodi(int);

int mapa[17][17];

//tabela maksimalnog N za neko L i H, za
//kojeg se moze svaki broj pogoditi
int dp(int L,int H)
{
    if(mapa[L][H]!=-1)
    {
        return mapa[L][H];
    }
    if(L==0)
        return H+1;
    if(H==0)
        return L+1;
    mapa[L][H]=dp(L-1,H)+1+dp(L,H-1);
    return mapa[L][H];
}

int nadji(int n,int L,int H,int off=0)
{
    if(!(L>15 || H>15) && n>dp(L,H))
        printf("Nesto ne valja!!");
    int novi=(n-1)/2;
    if(n==0 || n==1)
        novi=0;
    else if(H==0)
        novi=n-1;
    else if(L==0)
        novi=0;
    else if(L<16 && dp(L-1,H)<novi)
        novi=max(dp(L-1,H),0);
    else if(H<16 && dp(L,H-1)<n-novi-1)
        novi=max(n-dp(L,H-1)-1,0);
    int rez=pogodi(novi+off+1);
    if(rez==0)
        return 1;
    else if(rez==-1)
        return nadji(novi,L-1,H,off);
    else if(rez==1)
        return nadji(n-novi-1,L,H-1,off+novi+1);
}

void init(int n,int l, int h)
{
    memset(mapa,-1,sizeof mapa);
    nadji(n,l,h);
}
