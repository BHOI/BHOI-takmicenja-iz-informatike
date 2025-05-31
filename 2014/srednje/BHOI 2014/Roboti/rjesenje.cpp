#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF=1<<29;

struct edge
{
    int x,y;
    long long d;
    edge(){}
    edge(int _x,int _y, long long _d){x=_x;d=_d;y=_y;}
    bool operator <(const edge &o)const
    {
        return d>o.d;
    }
};

vector<vector<long long> > dist;
vector<vector<edge> > ve;
priority_queue<edge> pq;

void dijkstra(int u)
{
    while (!pq.empty())pq.pop();
    pq.push(edge(-1,u,0));
    dist[0][u]=0;
    edge tmp;
    long long neu;
    int ide;
    while (!pq.empty())
    {
        tmp=pq.top();pq.pop();
        if(dist[tmp.d%3][tmp.y]<tmp.d)continue;
        dist[tmp.d%3][tmp.y]=tmp.d;
        for(int i=0;i<ve[tmp.y].size();i++)
        {
            neu=tmp.d+ve[tmp.y][i].d;
            ide=ve[tmp.y][i].y;
            if(dist[neu%3][ide]>neu)
            {
                dist[neu%3][ide]=neu;
                pq.push(edge(-1,ide,neu));
            }
        }
    }
    return;
}

int BrojMinimalnihPotrosnji(int r, int p, int q, int v, int e, int* en) {
	int a,b,c;
	ve.clear();
	ve.resize(v);
	for(int i=0;i<e;i++)
	{
	    a=en[i*3];b=en[i*3+1];c=en[i*3+2];
	    a--;b--;
	    ve[a].push_back(edge(a,b,c));
	}
	c=0;
	for(int i=0;i<v;i++)
	{
	    dist.clear();
	    dist.resize(3,vector<long long>(v,INF));
	    dijkstra(i);
	    for(int j=0;j<v;j++)
	    {
	        if(dist[r][j]>=p && dist[r][j]<=q)
                c++;
	    }
	}
	return c;
}
