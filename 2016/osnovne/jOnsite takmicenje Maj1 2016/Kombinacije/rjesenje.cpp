#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
using namespace std;

int N,a[4][4];

bool isclose(int z[3])
{
    for(int i=0;i<2;i++)
    {
        bool ys=1;
        for(int j=0;j<3;j++)
        {
            if(min((a[i][j]-z[j]+N*2)%N,(z[j]-a[i][j]+N*2)%N)>2)ys=0;
        }
        if (ys) return 1;
    }
    return 0;
}

int main()
{
        FILE *in,*out;
        in=stdin;
        out=stdout;
        int t[3],c=0;
        fscanf(in,"%d",&N);
        fscanf(in,"%d %d %d",&a[0][0],&a[0][1],&a[0][2]);
        fscanf(in,"%d %d %d",&a[1][0],&a[1][1],&a[1][2]);
        for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
        for(int k=1;k<=N;k++)
        {
                t[0]=i;t[1]=j;t[2]=k;
                c+=isclose(t);
        }
        fprintf(out,"%d\n",c);
        return 0;
}
