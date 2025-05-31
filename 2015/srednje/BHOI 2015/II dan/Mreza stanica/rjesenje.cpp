#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
#define pb push_back
#define mp make_pair

struct edge
{
    int x,y,d;
    edge(){}
    edge(int x,int y,int d):x(x),y(y),d(d){}
    bool operator < (const edge &o)const
    {
        return d>o.d;
    }
};

vector<edge> svi;
vector<int> un;
int broj_s;
map<int,int> mapa;//stanica

int findx(int x){if(un[x]!=x)return un[x]=findx(un[x]);else return x;}

int spoji(int x,int y)
{
    if(x<y)swap(x,y);
    un[findx(y)]=findx(x);
}

void Stanice(int N, int S[], int Q)
{
    broj_s=N;
    int k=0;
    for(int i=0;i<N;i++)
        mapa[S[i]]=k++;
}

void PoveziStanice (int S1, int S2, int T, int V, int L[],
                    int A[], int B[], int C[])
{
    const int INF=1<<29;
    map<int,int> mapl;
    mapl[S1]=0;
    mapl[S2]=T+1;
    int k=1;
    for(int i=0;i<T;i++)
        mapl[L[i]]=k++;
    int n=T+2;
    vector<vector<edge> > ve;
    ve.resize(T+2);
    int x,y;
    for(int i=0;i<V;i++)
    {
        x=mapl[A[i]];
        y=mapl[B[i]];
        ve[x].pb(edge(x,y,C[i]));
        ve[y].pb(edge(y,x,C[i]));
    }
    vector<int> dist(n,INF);
    dist[0]=0;
    priority_queue<edge> pq;
    pq.push(edge(-1,0,0));
    edge tmp;
    while(!pq.empty())
    {
        tmp=pq.top();
        pq.pop();
        if(dist[tmp.y]==tmp.d)
        {
            //dist[tmp.y]=tmp.d;
            for(int i=0;i<ve[tmp.y].size();i++)
            {
                if(dist[ve[tmp.y][i].y]>tmp.d+ve[tmp.y][i].d)
                {
                    pq.push(edge(-1,ve[tmp.y][i].y,tmp.d+ve[tmp.y][i].d));
                    dist[ve[tmp.y][i].y]=tmp.d+ve[tmp.y][i].d;
                }
            }
        }
    }
    svi.pb(edge(mapa[S1],mapa[S2],dist[n-1]));
}

int UkupnaDuzina()
{
//obratno
    sort(svi.rbegin(),svi.rend());
    un.resize(broj_s);
    for(int i=0;i<broj_s;i++)
        un[i]=i;
    int rez=0;
    for(int i=0;i<svi.size();i++)
    {
        if(findx(svi[i].x)!=findx(svi[i].y))
        {
            spoji(svi[i].x,svi[i].y);
            rez+=svi[i].d;
        }
    }
    return rez;
}

//int main()
//{
//    freopen("in.txt","r",stdin);
//	void Stanice(int,int[],int);
//	void PoveziStanice(int, int, int, int, int[], int[], int[], int[]);
//	int UkupnaDuzina();
//
//	int n,q,t,v,i,j,s1,s2;
//	if(scanf("%d",&n)!=1)return 1;
//	int *s=(int*)calloc(n,sizeof(int));
//	for(i=0;i<n;i++)
//		if(scanf("%d",&s[i])!=1)return 1;
//	if(scanf("%d",&q)!=1)return 1;
//	Stanice(n,s,q);
//	free(s);
//	int *l,*a,*b,*c;
//	for(i=0;i<q;i++)
//	{
//		if(scanf("%d %d %d %d",&s1,&s2,&t,&v)!=4)return 1;
//		l=(int*)calloc(t,sizeof(int));
//		for(j=0;j<t;j++)
//			if(scanf("%d",&l[j])!=1)return 1;
//		a=(int*)calloc(v,sizeof(int));
//		b=(int*)calloc(v,sizeof(int));
//		c=(int*)calloc(v,sizeof(int));
//		for(j=0;j<v;j++)
//			if(scanf("%d %d %d",&a[j],&b[j],&c[j])!=3)return 1;
//		PoveziStanice(s1,s2,t,v,l,a,b,c);
//		free(a);free(b);free(c);free(l);
//	}
//	printf("%d\n",UkupnaDuzina());
//	return 0;
//}
