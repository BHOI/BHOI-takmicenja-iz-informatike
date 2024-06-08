#include<bits/stdc++.h>


using namespace std;

const int sz1=1<<16;
int sz = 1;
vector<int> tree[4*sz1];
int a[sz1+5];
double ans[sz1+5];
int n,q;

void promeni(int x)
{
       int l=0;
       int r=0;
       int id1=2*x;
       int id2=2*x+1;

       while(l<tree[id1].size() || r<tree[id2].size())
       {
        if (l==tree[id1].size())
        {
           tree[x][l+r]=(tree[id2][r]);
           r++;
         } else
         if (r==tree[id2].size())
         {
            tree[x][l+r]=(tree[id1][l]);
            l++;
         } else
           if (tree[id1][l]<tree[id2][r])
           {
              tree[x][l+r]=(tree[id1][l]);
              l++;
           } else
           {
               tree[x][l+r]=(tree[id2][r]);
               r++;
           }
       }
}
void kreiraj(int x)
{
for (int i=0;i<tree[2*x].size()+tree[2*x+1].size();i++)
    tree[x].push_back(1e5);
}
void napravi()
{
   for (int i=sz;i<2*sz;i++)
    tree[i].push_back(a[i-sz+1]);
    for (int i=sz-1;i>0;i--)
    kreiraj(i);
    for (int i=sz-1;i>0;i--)
    promeni(i);
}
int get(int cur, int tl, int tr, int l, int r, int val)
{
   if (tl>r || tr<l) return 0;
   if (tl>=l && tr<=r)
   {
        int lo=0;
        int hi=tree[cur].size();

        while(lo<hi-1)
        {
            int mid=(lo+hi)/2;
            if (tree[cur][mid]<=val) lo=mid; else hi=mid;
        }

        if (tree[cur][lo]<=val) return (lo+1); else return lo;

   }
   int an1=get(2*cur,tl,(tl+tr)/2,l,r,val);
   int an2=get(2*cur+1,(tr+tl)/2+1,tr,l,r,val);
   return an1+an2;
}
int nadji(int l, int r,int tr)
{
     int lo=0;
     int hi=5e4+5;
     while(lo<hi-1)
     {
         int val=(hi+lo)/2;
         if (get(1,1,sz,l,r,val)<tr) lo=val; else hi=val;
     }
     return (lo+1);
}
void odgovori(int br, int l, int r)
{
    int len=(r-l+1);
    if (len%2)
      ans[br]=nadji(l,r,len/2+1); else
      ans[br]=((double)nadji(l,r,len/2)+nadji(l,r,len/2+1))/2.00;

}
void update(int poz,int val)
{
   int cur=poz+sz-1;
   tree[cur][0]=val;
    cur/=2;
   while(cur>0)
   {
      promeni(cur);
      cur/=2;
   }
}


void medijana(int *A, int N, int *T, int *X, int *Y, int Q, double *R) {
    q = Q;
    n = N;
    while (sz <= n) sz*=2;
    for (int i = 0; i < n; i++) a[i+1] = A[i];
    for (int i=n+1; i<=sz; i++)
        a[i]=1e5;

    for (int i=0; i<q; i++)
        ans[i]=-1;
    napravi();
    int idx = 0;
    for (int i=0; i<q; i++)
    {
        int tip = T[i];
        if (tip==1)
        {
            int x=X[i], y=Y[i];
            x++;
            a[x]=y;
            update(x,y);
        }
        else
        {
            int l=X[i], r=Y[i];
            l++;
            r++;
            odgovori(idx,l,r);
            R[idx]=ans[idx];
            idx++;
        }
    }
}


